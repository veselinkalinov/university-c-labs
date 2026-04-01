#include <stdio.h>

int main() {
  int a, b, c;
  printf("Enter 3 nums: ");
  int count = scanf("%d %d %d", &a, &b, &c);

  if (count != 3) {
    printf("Error: expected exactly 3 numbers.\n");
    return 1;
  }

  if (a == b && b == c) {
    printf("yes\n");
  } else {
    printf("no\n");
  }

  return 0;
}
