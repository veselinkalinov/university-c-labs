#include <stdio.h>
#include <stdlib.h>

double averageArray(const int *arr, int size);

int main(void) {
  int n;

  printf("Enter number of elements: ");
  scanf("%d", &n);

  int *arr = (int *)malloc(n * sizeof(int));
  if (arr == NULL) {
    printf("malloc error!\n");
    exit(1);
  }

  for (int i = 0; i < n; i++) {
    printf("arr[%d] = ", i);
    scanf("%d", &arr[i]);
  }

  printf("Average value = %.2lf\n", averageArray(arr, n));

  free(arr);
  return 0;
}

double averageArray(const int *arr, int size) {
  int sum = 0;

  for (int i = 0; i < size; i++) {
    sum += arr[i];
  }

  return (double)sum / size;
}
