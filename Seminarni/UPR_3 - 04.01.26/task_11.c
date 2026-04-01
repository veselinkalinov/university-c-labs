#include <stdio.h>

int main() {
  int n;
  printf("Enter n: ");
  scanf("%d", &n);

  int arr[100];
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  int minVal = arr[0], minIdx = 0;
  int maxVal = arr[0], maxIdx = 0;

  for (int i = 1; i < n; i++) {
    if (arr[i] < minVal) {
      minVal = arr[i];
      minIdx = i;
    }
    if (arr[i] > maxVal) {
      maxVal = arr[i];
      maxIdx = i;
    }
  }

  printf("Min el: %d, index: %d\n", minVal, minIdx);
  printf("Max el: %d, index: %d\n", maxVal, maxIdx);

  return 0;
}
