#include <stdio.h>

int main(void) {
    int a[4][5];
    int rowSum[4];
    int minSum;

    printf("Enter the elements of the 4x5 matrix:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 0; i < 4; i++) {
        rowSum[i] = 0;
        for (int j = 0; j < 5; j++) {
            rowSum[i] += a[i][j];
        }
    }

    minSum = rowSum[0];
    for (int i = 1; i < 4; i++) {
        if (rowSum[i] < minSum) {
            minSum = rowSum[i];
        }
    }

    printf("\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%6d", a[i][j]);
        }
        printf("%6d\n", rowSum[i]);
    }

    printf("%18d\n", minSum);

    return 0;
}
