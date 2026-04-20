#include <stdio.h>

int main(void) {
    int n, m;
    int matrix[100][100];
    int rowsAscending = 1;
    int colsDescending = 1;

    printf("Enter rows and cols: ");
    scanf("%d %d", &n, &m);

    printf("Enter the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m - 1; j++) {
            if (matrix[i][j] > matrix[i][j + 1]) {
                rowsAscending = 0;
            }
        }
    }

    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n - 1; i++) {
            if (matrix[i][j] < matrix[i + 1][j]) {
                colsDescending = 0;
            }
        }
    }

    if (rowsAscending) {
        printf("Every row is sorted in ascending order.\n");
    } else {
        printf("Not every row is sorted in ascending order.\n");
    }

    if (colsDescending) {
        printf("Every column is sorted in descending order.\n");
    } else {
        printf("Not every column is sorted in descending order.\n");
    }

    if (rowsAscending && colsDescending) {
        printf("The matrix satisfies both conditions.\n");
    } else {
        printf("The matrix does not satisfy both conditions.\n");
    }

    return 0;
}
