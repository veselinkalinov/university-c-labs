#include <stdio.h>

int main() {
  int n;
  printf("Enter N:");
  scanf("%d", &n);

  int arr[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  int k;
  printf("Enter K:");
  scanf("%d", &k);

  for (int i = 0; i < k; i++) {
    int max = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] > arr[max]) {
        max = j;
      }
    }
    int temp = arr[i];
    arr[i] = arr[max];
    arr[max] = temp;
  }
  printf("%d element: %d", k, arr[k - 1]);
  return 0;
}
