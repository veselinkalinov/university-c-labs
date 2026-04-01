#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int n;
  printf("Enter N: ");
  scanf("%d", &n);

  int **mat = (int **)malloc(n * sizeof(int *));
  if (mat == NULL) {
    exit(1);
  }
  for (int i = 0; i < n; i++) {
    mat[i] = (int *)malloc(n * sizeof(int));
    if (mat[i] == NULL) {
      exit(1);
    }
  }

  printf("Enter matrix elements (%dx%d):\n", n, n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &mat[i][j]);
    }
  }

  printf("\nа. Main:\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", mat[i][i]);
  }
  printf("\n");

  printf("\nb. Secondary:\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", mat[i][n - 1 - i]);
  }
  printf("\n");

  printf("\nc. Above maim:\n");
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      printf("%d ", mat[i][j]);
    }
  }
  printf("\n");

  printf("\nd. Under main:\n");
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      printf("%d ", mat[i][j]);
    }
  }
  printf("\n");

  for (int i = 0; i < n; i++) {
    free(mat[i]);
  }
  free(mat);

  return 0;
}
