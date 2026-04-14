#include <stdio.h>
#include <stdlib.h>

double averageArray(const int *arr, int size);
int *addElementsFromStart(int *arr, int size, int countToAdd);

int main(void) {
  int n;

  printf("Enter number of elements: ");
  scanf("%d", &n);

  int *arr = (int *)malloc(n * sizeof(int));
  if (arr == NULL) {
    printf("malloc error!\n");
    return 1;
  }

  for (int i = 0; i < n; i++) {
    printf("arr[%d] = ", i);
    scanf("%d", &arr[i]);
  }

  double average = averageArray(arr, n);
  int countToAdd = (int)average;
  int oldSize = n;

  arr = addElementsFromStart(arr, oldSize, countToAdd);
  if (arr == NULL) {
    printf("malloc error!\n");
    return 1;
  }

  n = oldSize + countToAdd;

  printf("Average value = %.2lf\n", average);
  printf("New array: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  free(arr);
  return 0;
}

int *addElementsFromStart(int *arr, int size, int countToAdd) {
  if (countToAdd <= 0) {
    return arr;
  }

  int *newArr = (int *)realloc(arr, (size + countToAdd) * sizeof(int));
  if (newArr == NULL) {
    return NULL;
  }

  for (int i = 0; i < countToAdd; i++) {
    newArr[size + i] = newArr[i % size];
  }

  return newArr;
}

double averageArray(const int *arr, int size) {
  int sum = 0;

  for (int i = 0; i < size; i++) {
    sum += arr[i];
  }

  return (double)sum / size;
}
