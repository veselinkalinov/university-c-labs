#include <stdio.h>

int sum_below_main_diagonal(int size, int (*matrix)[size]) {
  int sum = 0;
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (i > j) {
        sum += *(*(matrix + i) + j);
      }
    }
  }
  return sum;
}

int main() {
  int size = 3;
  int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  printf("%d\n", sum_below_main_diagonal(size, matrix));

  return 0;
}
