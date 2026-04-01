#include <stdio.h>

int main() {
  int n;
  printf("Enter N: ");
  scanf("%d", &n);

  int arr[100];
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  int x;
  printf("Enter x: ");
  scanf("%d", &x);

  int count = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] == x) {
      count++;
    }
  }

  printf("x = %d is current %d times.\n", x, count);

  return 0;
}
