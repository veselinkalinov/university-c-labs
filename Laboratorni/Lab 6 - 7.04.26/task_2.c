#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int n = 7;
  int *arr = (int *)malloc(n * sizeof(int));
  if (arr == NULL) {
    exit(1);
  }

  printf("Enter %d numbers[-5000..5000]:\n", n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  int max = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }

  printf("Max: %d\n", max);

  free(arr);
  return 0;
}
