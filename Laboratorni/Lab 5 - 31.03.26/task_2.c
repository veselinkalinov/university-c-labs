#include <stdio.h>

double array_avg(int *arr1, int size1, int *arr2, int size2) {
  double sum = 0;
  int *p;

  for (p = arr1; p < arr1 + size1; p++) {
    sum += *p;
  }

  for (p = arr2; p < arr2 + size2; p++) {
    sum += *p;
  }
  return sum / (size1 + size2);
}

int main() {
  int arr1[] = {1, 2, 3, 4};
  int arr2[] = {5, 6, 7};
  int size1 = sizeof(arr1) / sizeof(arr1[0]);
  int size2 = sizeof(arr2) / sizeof(arr2[0]);
  printf("%.2f\n", array_avg(arr1, size1, arr2, size2));
  return 0;
}
