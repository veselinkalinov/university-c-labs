#include <stdio.h>

int main(void) {
    int n, m;
    int matrix[100][100];
    int minValue, maxValue;
    int minRow = 0, maxRow = 0;

    printf("Enter rows and cols: ");
    scanf("%d %d", &n, &m);

    printf("Enter the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    minValue = matrix[0][0];
    maxValue = matrix[0][0];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] < minValue) {
                minValue = matrix[i][j];
                minRow = i;
            }
            if (matrix[i][j] > maxValue) {
                maxValue = matrix[i][j];
                maxRow = i;
            }
        }
    }

    if (minRow != maxRow) {
        for (int j = 0; j < m; j++) {
            int temp = matrix[minRow][j];
            matrix[minRow][j] = matrix[maxRow][j];
            matrix[maxRow][j] = temp;
        }
    }

    printf("Result matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
