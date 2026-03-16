#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int n;
  printf("Enter number of integers: ");
  scanf("%d", &n);

  // allocate n integers
  int *arr = malloc(n * sizeof(int));

  if (arr == NULL) {
    fprintf(stderr, "malloc failed\n");
    return 1;
  }

  // memory is uninitialized — write before reading
  for (int i = 0; i < n; i++) {
    arr[i] = i * 2;
  }

  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  free(arr);
  return 0;
}
