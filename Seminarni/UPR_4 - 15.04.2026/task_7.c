#include <stdio.h>

int main(void) {
    int n, m;
    int matrix[100][100];
    int bestRow = 0, bestCol = 0;
    int minSum;

    printf("Enter rows and cols: ");
    scanf("%d %d", &n, &m);

    if (n < 3 || m < 3) {
        printf("A 3x3 submatrix cannot be formed.\n");
        return 0;
    }

    printf("Enter the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    minSum = 2147483647;

    for (int i = 0; i <= n - 3; i++) {
        for (int j = 0; j <= m - 3; j++) {
            int sum = 0;

            for (int r = i; r < i + 3; r++) {
                for (int c = j; c < j + 3; c++) {
                    sum += matrix[r][c];
                }
            }

            if (sum < minSum) {
                minSum = sum;
                bestRow = i;
                bestCol = j;
            }
        }
    }

    printf("3x3 submatrix with minimum sum:\n");
    for (int i = bestRow; i < bestRow + 3; i++) {
        for (int j = bestCol; j < bestCol + 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("Minimum sum = %d\n", minSum);

    return 0;
}
