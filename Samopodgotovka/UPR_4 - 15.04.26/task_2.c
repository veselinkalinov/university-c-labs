#include <stdio.h>

int main(void) {
    int n, m;
    int matrix[100][100];
    int bestRow = 0, bestCol = 0;
    int maxNeighborSum;

    printf("Enter rows and cols: ");
    scanf("%d %d", &n, &m);

    printf("Enter the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    maxNeighborSum = -2147483647;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int sum = 0;

            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    if (di == 0 && dj == 0) {
                        continue;
                    }

                    if (i + di >= 0 && i + di < n && j + dj >= 0 && j + dj < m) {
                        sum += matrix[i + di][j + dj];
                    }
                }
            }

            if (sum > maxNeighborSum) {
                maxNeighborSum = sum;
                bestRow = i;
                bestCol = j;
            }
        }
    }

    printf("Element with maximum neighbor sum: %d\n", matrix[bestRow][bestCol]);
    printf("Position: row %d, col %d\n", bestRow, bestCol);
    printf("Neighbor sum: %d\n", maxNeighborSum);

    return 0;
}
