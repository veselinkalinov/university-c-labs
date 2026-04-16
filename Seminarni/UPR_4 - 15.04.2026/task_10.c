#include <stdio.h>

int main(void) {
    int n, m;
    int matrix[100][100];

    printf("Enter rows and cols: ");
    scanf("%d %d", &n, &m);

    printf("Enter the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Sum of each column:\n");
    for (int j = 0; j < m; j++) {
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += matrix[i][j];
        }

        printf("Column %d -> %d\n", j, sum);
    }

    return 0;
}
