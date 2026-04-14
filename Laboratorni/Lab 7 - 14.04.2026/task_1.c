#include <stdio.h>
#define SIZE 5

void reverseArr(int *arr, int size);

int main(void) {
  int arr[SIZE] = {1, 2, 3, 4, 5};
  for (int i = 0; i < SIZE; i++) {
    printf("arr[%d] = %d\n", i, arr[i]);
  }
  reverseArr(arr, SIZE);
  for (int i = 0; i < SIZE; i++) {
    printf("arr[%d] = %d\n", i, arr[i]);
  }

  return 0;
}

void reverseArr(int *arr, int size) {
  int start = 0, end = size - 1, temp;
  for (; size <= end; end--) {
    temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
  }
}
