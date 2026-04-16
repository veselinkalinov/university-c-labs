#include <stdio.h>

int main(void) {
    int n;
    int a[100][100];
    int b[100][100];
    int hasNegativeBelowMain = 0;

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter matrix A:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
            b[i][j] = 0;
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i][j] < 0) {
                hasNegativeBelowMain = 1;
            }
        }
    }

    if (hasNegativeBelowMain) {
        for (int i = 0; i < n; i++) {
            b[i][i] = 1;
        }
    } else {
        for (int i = 0; i < n; i++) {
            b[i][n - 1 - i] = -1;
        }
    }

    printf("Matrix A:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }

    printf("Matrix B:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d", b[i][j]);
        }
        printf("\n");
    }

    return 0;
}
