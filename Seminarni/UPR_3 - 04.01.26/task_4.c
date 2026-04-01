#include <stdio.h>

int main() {
  int n;
  printf("Enter number of elements: ");
  scanf("%d", &n);

  int arr[100];
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  int k;
  printf("Enter k: ");
  scanf("%d", &k);
  k = k % n;

  int temp[100];
  for (int i = 0; i < n; i++) {
    temp[(i + k) % n] = arr[i];
  }

  for (int i = 0; i < n; i++) {
    printf("%d ", temp[i]);
  }
  printf("\n");

  return 0;
}
