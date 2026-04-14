#include <stdio.h>
#include <stdlib.h>

double averageArray(const int *arr, int size);
void addAverageCountElements(int **arr, int *size);
void printArray(const int *arr, int size);

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

  printf("Average value = %.2lf\n", averageArray(arr, n));
  addAverageCountElements(&arr, &n);

  printf("New array:\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  free(arr);
  return 0;
}

void addAverageCountElements(int **arr, int *size) {
  int countToAdd = (int)averageArray(*arr, *size);
  int oldSize = *size;

  if (countToAdd <= 0) {
    return;
  }

  *arr = (int *)realloc(*arr, (oldSize + countToAdd) * sizeof(int));
  if (*arr == NULL) {
    printf("realloc error!\n");
    exit(1);
  }

  for (int i = 0; i < countToAdd; i++) {
    (*arr)[oldSize + i] = (*arr)[i % oldSize];
  }

  *size = oldSize + countToAdd;
}

double averageArray(const int *arr, int size) {
  int sum = 0;

  for (int i = 0; i < size; i++) {
    sum += arr[i];
  }

  return (double)sum / size;
}
