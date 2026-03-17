#include <stdio.h>

int main() {
  int n;
  int k;
  int a;
  int sum = 0;
  int prod = 1;

  printf("Enter number N:");
  scanf("%d", &n);
  printf("Enter number K:");
  scanf("%d", &k);

  for (int i = 0; i < n; i++) {
    printf("Enter Number %d:", i + 1);
    scanf("%d", &a);
    if (a % 2 == 0 && a < k) {
      sum += a;
    }
    if (a % 3 == 0 && a > k) {
      prod *= a;
    }
  }

  printf("Sum = %d\n", sum);
  printf("Prod = %d\n", prod);

  return 0;
}
