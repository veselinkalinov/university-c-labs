#include <stdio.h>

#define MAX_EMPLOYEES 30
#define REGULAR_HOURS 40
#define OVERTIME_RATE 1.5
#define TAX_RATE      0.0365
#define FILENAME      "employees.bin"

typedef struct {
    int    id;
    double hourly_rate;
    int    hours_worked;
    double weekly_salary;
} Employee;

double calculate_salary(double rate, int hours) {
    double gross;
    if (hours <= REGULAR_HOURS) {
        gross = rate * hours;
    } else {
        int overtime = hours - REGULAR_HOURS;
        gross = rate * REGULAR_HOURS + rate * OVERTIME_RATE * overtime;
    }
    return gross * (1.0 - TAX_RATE);
}

int count_employees() {
    FILE *f = fopen(FILENAME, "rb");
    if (!f) return 0;
    int count = 0;
    Employee e;
    while (fread(&e, sizeof(Employee), 1, f) == 1) count++;
    fclose(f);
    return count;
}

void add_employee() {
    if (count_employees() >= MAX_EMPLOYEES) {
        printf("Maximum number of employees reached (%d).\n", MAX_EMPLOYEES);
        return;
    }

    Employee e;
    printf("ID: ");
    scanf("%d", &e.id);
    printf("Hourly rate: ");
    scanf("%lf", &e.hourly_rate);
    printf("Hours worked this week: ");
    scanf("%d", &e.hours_worked);

    e.weekly_salary = calculate_salary(e.hourly_rate, e.hours_worked);

    FILE *f = fopen(FILENAME, "ab");
    if (!f) { printf("Error opening file.\n"); return; }
    fwrite(&e, sizeof(Employee), 1, f);
    fclose(f);

    printf("Employee added. Weekly salary (after tax): %.2f\n", e.weekly_salary);
}

void display_salaries() {
    FILE *f = fopen(FILENAME, "rb");
    if (!f) { printf("No records found.\n"); return; }

    Employee e;
    int found = 0;

    printf("\n%-6s %-14s %-8s %-16s\n", "ID", "Hourly Rate", "Hours", "Weekly Salary");
    printf("--------------------------------------------------\n");

    while (fread(&e, sizeof(Employee), 1, f) == 1) {
        printf("%-6d %-14.2f %-8d %-16.2f\n",
               e.id, e.hourly_rate, e.hours_worked, e.weekly_salary);
        found = 1;
    }

    if (!found) printf("No employees in file.\n");
    fclose(f);
}

int main() {
    int choice;

    do {
        printf("\n=== Employee Management ===\n");
        printf("1. Add new employee\n");
        printf("2. Display all salaries\n");
        printf("0. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: add_employee();    break;
            case 2: display_salaries(); break;
            case 0: printf("Goodbye.\n"); break;
            default: printf("Invalid option.\n");
        }
    } while (choice != 0);

    return 0;
}
