#include <stdio.h>

void sort(int arr[], int size) {
  int sorted;
  for (int i = 0; i < size - 1; i++) {
    sorted = 0;
    for (int j = 0; j < size - (i + 1); j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        sorted = 1;
      }
    }
    if (sorted == 0) {
      break;
    }
  }
}

void print(int arr[], int size) {
  for (int i = 0; i < size; i++)
    printf("%d ", arr[i]);
}
