#include <stdio.h>
#include <stdlib.h>

int main(void) {
  // clang-format off
    //int array[3][3] = {{1, 2, 3},
    //                   {4, 5, 6},
  //                     {7, 8, 9}};
  // clang-format on
  int rows = 5;
  int cols = 5;

  int **array = malloc(sizeof(int *) * 3);

  for (int i = 0; i < rows; i++) {
    array[i] = malloc(sizeof(int) * 3);
  }

  for (int i = 0; i < rows; i++) {
    free(array[i]);
  }

  array[1][2] = 5;

  printf("array[1][2]= %d\n", array[1][2]);

  free(array);
  return 0;
}
