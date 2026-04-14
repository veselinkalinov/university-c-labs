#include <stdio.h>
#define SIZE 5

void reverseArr(int *arr, int size);

int main(void) {
  int arr[SIZE] = {1, 2, 3, 4, 5};

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
