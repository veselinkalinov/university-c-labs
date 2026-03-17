#include <stdio.h>

int main() {
  int num = 1, sum = 0;

  for (int i = 1; num != 0; i++) {
    printf("Enter number %d:", i);
    scanf("%d", &num);
    sum += num;
  }

  printf("Sum = %d", sum);

  return 0;
}
