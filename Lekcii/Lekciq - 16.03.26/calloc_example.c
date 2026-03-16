#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int n = 5;

  // allocate 5 integers, all initialized to 0
  int *arr = calloc(n, sizeof(int));

  if (arr == NULL) {
    fprintf(stderr, "calloc failed\n");
    return 1;
  }

  // all elements are guaranteed to be 0
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]); // prints: 0 0 0 0 0
  }
  printf("\n");

  free(arr);
  return 0;
}
