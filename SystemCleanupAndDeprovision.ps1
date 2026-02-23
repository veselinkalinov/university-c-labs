<#
.SYNOPSIS
    System Optimization & De-provisioning Script
.DESCRIPTION
    Phase 1: Identifies dump files, unused apps (>90 days), and temp directories.
    Phase 2: Validates against active processes, critical system paths, and Windows services.
    Phase 3: Creates a CSV manifest and moves items to a quarantine folder, scheduling a task to delete them after 7 days.
    Phase 4: Outputs a summary report.
.NOTES
    This script requires Administrator privileges to access C:\Program Files, check Services, and register Scheduled Tasks.
#>

# Ensure Administrator privileges
if (-not ([Security.Principal.WindowsPrincipal][Security.Principal.WindowsIdentity]::GetCurrent()).IsInRole([Security.Principal.WindowsBuiltInRole]::Administrator)) {
    Write-Warning "This script must be run as Administrator."
    Exit
}

$ErrorActionPreference = "SilentlyContinue"

# Settings
$QuarantineDir = "C:\SystemCleanup_Quarantine"
$ExcludedPaths = @("C:\Windows", "C:\Users\Public", "C:\Boot", $QuarantineDir)
$ReportData = @()
$SkippedItems = @()
$TotalReclaimedGB = 0

# ==========================================
# PHASE 2: Validation (Safety Filters)
# ==========================================

function Test-SystemProtection {
    param([string]$Target)
    foreach ($exc in $ExcludedPaths) {
        if ($Target.StartsWith($exc, [StringComparison]::OrdinalIgnoreCase) -or $Target -eq $exc) {
            return $true
        }
    }
    return $false
}

function Test-ProcessGuard {
    param([string]$Target)
    $TargetStr = $Target.TrimEnd('\')

    # Check if any running process resides in the target directory constraint
    $processes = Get-Process | Where-Object { -not [string]::IsNullOrWhiteSpace($_.Path) }
    foreach ($p in $processes) {
        if ($p.Path.StartsWith($TargetStr, [StringComparison]::OrdinalIgnoreCase) -or $p.Path -eq $TargetStr) {
            return $true
        }
    }

    # If it is a file, trying to get read lock access
    if (Test-Path -LiteralPath $Target -PathType Leaf) {
        try {
            $stream = [System.IO.File]::Open($Target, 'Open', 'Read', 'None')
            $stream.Close()
        } catch {
            return $true # File is in use
        }
    }
    return $false
}

function Test-ServiceCheck {
    param([string]$Target)
    $TargetStr = $Target.TrimEnd('\')

    $services = Get-WmiObject win32_service | Where-Object { -not [string]::IsNullOrWhiteSpace($_.PathName) }
    foreach ($s in $services) {
        $svcPath = $s.PathName -replace '"', ''
        if ($svcPath.StartsWith($TargetStr, [StringComparison]::OrdinalIgnoreCase) -or $svcPath -eq $TargetStr) {
            return $true
        }
    }
    return $false
}

# ==========================================
# PHASE 3 Helper: Action (Execution Logic)
# ==========================================

function Process-DeprovisioningItem {
    param(
        [System.IO.FileSystemInfo]$Item,
        [string]$Category
    )

    $Path = $Item.FullName

    # 1. System Protection Guard
    if (Test-SystemProtection $Path) { return }

    # 2. Process Guard
    if (Test-ProcessGuard $Path) {
        $script:SkippedItems += [PSCustomObject]@{
            Path   = $Path
            Reason = "Process Guard"
        }
        return
    }

    # 3. Service Check
    if (Test-ServiceCheck $Path) {
        $script:SkippedItems += [PSCustomObject]@{
            Path   = $Path
            Reason = "Service Check"
        }
        return
    }

    # Calculate Object Size
    $sizeGB = 0
    if ($Item -is [System.IO.DirectoryInfo]) {
        $sizeBytes = (Get-ChildItem -LiteralPath $Path -Recurse -File | Measure-Object -Property Length -Sum).Sum
        if ($sizeBytes) { $sizeGB = [Math]::Round($sizeBytes / 1GB, 4) }
    } else {
        $sizeGB = [Math]::Round($Item.Length / 1GB, 4)
    }

    # Manifest Entry
    $script:ReportData += [PSCustomObject]@{
        Path           = $Path
        SizeGB         = $sizeGB
        LastAccessTime = $Item.LastAccessTime
        Category       = $Category
    }

    $script:TotalReclaimedGB += $sizeGB

    # Staged Deletion
    if (-not (Test-Path -LiteralPath $QuarantineDir)) {
        New-Item -ItemType Directory -Path $QuarantineDir -Force | Out-Null
    }

    $destName = $Item.Name
    $destPath = Join-Path $QuarantineDir $destName
    $counter = 1
    while (Test-Path -LiteralPath $destPath) {
        $destPath = Join-Path $QuarantineDir "$destName`_$counter"
        $counter++
    }

    # Relocate Folder/File
    Move-Item -LiteralPath $Path -Destination $destPath -Force
}

# ==========================================
# PHASE 1: Identification (Scan & Detect)
# ==========================================
Write-Host "Starting System Optimization & De-provisioning..." -ForegroundColor Cyan

# 1. Target Dumps
Write-Host "-> Scanning for memory dumps..."
$dumpRoots = @("$env:SystemRoot\Minidump", "$env:LOCALAPPDATA\CrashDumps", "C:\")
foreach ($loc in $dumpRoots) {
    if (Test-Path -LiteralPath $loc) {
        $depth = if ($loc -match "^C:\\$") { 1 } else { 20 }
        Get-ChildItem -LiteralPath $loc -Include *.dmp, *.mdmp, memory.dmp -File -Recurse -Depth $depth |
            ForEach-Object { Process-DeprovisioningItem $_ "Dump File" }
    }
}

# 2. Identify Unused Apps & Inactivity Filter
Write-Host "-> Scanning for unused application installations (>90 days inactive)..."
$90DaysAgo = (Get-Date).AddDays(-90)
$programFolders = @("C:\Program Files", "C:\Program Files (x86)")

$uninstallKeys = @(
    "HKLM:\Software\Microsoft\Windows\CurrentVersion\Uninstall\*",
    "HKLM:\Software\Wow6432Node\Microsoft\Windows\CurrentVersion\Uninstall\*",
    "HKCU:\Software\Microsoft\Windows\CurrentVersion\Uninstall\*"
)
$installedApps = Get-ItemProperty -Path $uninstallKeys | Where-Object { $_.DisplayName -and $_.InstallLocation }

foreach ($folder in $programFolders) {
    if (Test-Path -LiteralPath $folder) {
        Get-ChildItem -LiteralPath $folder -Directory | Where-Object { $_.LastAccessTime -lt $90DaysAgo } | ForEach-Object {
            $dirInfo = $_
            $matchApp = $installedApps | Where-Object { $dirInfo.FullName -like "$($_.InstallLocation)*" }
            $category = if ($matchApp) { "Unused App (>90 days) - $($matchApp[0].DisplayName)" } else { "Inactive Directory (>90 days)" }
            Process-DeprovisioningItem $dirInfo $category
        }
    }
}

# 3. Temp Installations
Write-Host "-> Scanning for temporary installations..."
$tempLocations = @($env:TEMP, "C:\")
foreach ($loc in $tempLocations) {
    if (Test-Path -LiteralPath $loc) {
        $depth = if ($loc -match "^C:\\$") { 1 } else { 3 }
        Get-ChildItem -LiteralPath $loc -Directory -Recurse -Depth $depth |
            Where-Object { $_.Name -match "setup|install|_unpack_" } |
            ForEach-Object { Process-DeprovisioningItem $_ "Temp Installation" }
    }
}

# ==========================================
# PHASE 3: Action (Execution Logic)
# ==========================================
Write-Host "-> Setting up Manifest & Scheduled Task..."

if ($ReportData.Count -gt 0) {
    $manifestPath = Join-Path $QuarantineDir "CleanupManifest.csv"
    $ReportData | Export-Csv -Path $manifestPath -NoTypeInformation
}

# Scheduled Task Logic
$taskName = "SystemOptimization_QuarantinePurge"
$taskAction = New-ScheduledTaskAction -Execute "PowerShell.exe" -Argument "-WindowStyle Hidden -Command `"Remove-Item -Path '$QuarantineDir\*' -Recurse -Force`""
$taskTrigger = New-ScheduledTaskTrigger -Once -At (Get-Date).AddDays(7)
$taskPrincipal = New-ScheduledTaskPrincipal -UserId "SYSTEM" -LogonType ServiceAccount -RunLevel Highest

Register-ScheduledTask -TaskName $taskName -Action $taskAction -Trigger $taskTrigger -Principal $taskPrincipal -Force | Out-Null
$taskStatus = Get-ScheduledTask -TaskName $taskName


# ==========================================
# PHASE 4: Reporting
# ==========================================
Write-Host "`n==================================================" -ForegroundColor Green
Write-Host "          CLEANUP OPERATIONS SUMMARY" -ForegroundColor Green
Write-Host "==================================================" -ForegroundColor Green

Write-Host "Total space reclaimed : $TotalReclaimedGB GB`n"

Write-Host "Skipped Items (In-Use):"
if ($SkippedItems.Count -gt 0) {
    $SkippedItems | Format-Table -AutoSize | Out-String | Write-Host
} else {
    Write-Host "  None`n"
}

Write-Host "Scheduled Task Verification ($taskName):"
if ($taskStatus) {
    Write-Host "  Status    : Successfully Registered"
    Write-Host "  Next Run  : $($taskStatus.Triggers[0].StartBoundary)"
} else {
    Write-Host "  Status    : Failed to Register / Task not found"
}
Write-Host "==================================================" -ForegroundColor Green
