#include <stdio.h>
#include <stdlib.h>

double findAverage(const int *arr, int size);
void printArray(const int *arr, int size);

int main(void) {
  int n;

  printf("Enter number of elements: ");
  scanf("%d", &n);

  int *arr = (int *)malloc(n * sizeof(int));
  if (arr == NULL) {
    printf("Memory allocation error!\n");
    return 1;
  }

  for (int i = 0; i < n; i++) {
    printf("arr[%d] = ", i);
    scanf("%d", &arr[i]);
  }

  double average = findAverage(arr, n);
  int countToAdd = (int)average;
  int oldSize = n;

  if (countToAdd > 0) {
    arr = (int *)realloc(arr, (n + countToAdd) * sizeof(int));
    if (arr == NULL) {
      printf("Memory reallocation error!\n");
      return 1;
    }

    for (int i = 0; i < countToAdd; i++) {
      arr[oldSize + i] = arr[i % oldSize];
    }

    n += countToAdd;
  }

  printf("Average value = %.2lf\n", average);
  printf("New array:\n");
  printArray(arr, n);

  free(arr);
  return 0;
}

double findAverage(const int *arr, int size) {
  int sum = 0;

  for (int i = 0; i < size; i++) {
    sum += arr[i];
  }

  return (double)sum / size;
}

void printArray(const int *arr, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
