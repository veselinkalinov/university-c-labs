#include <stdio.h>

int main() {
  int a;
  int b;
  char symbol;

  printf("Enter a:");
  scanf("%d", &a);
  printf("Enter b:");
  scanf("%d", &b);
  printf("Enter math operation (+, -, *, /):");
  scanf(" %c", &symbol);

  if (symbol == '+') {
    printf("%d + %d = %d", a, b, a + b);
  } else if (symbol == '-') {
    printf("%d - %d = %d", a, b, a - b);
  } else if (symbol == '*') {
    printf("%d * %d = %d", a, b, a * b);
  } else if (symbol == '/') {
    if (b != 0) {
      printf("%d / %d = %d", a, b, a / b);
    } else {
      printf("\nError: Division by zero!");
    }
  } else {
    printf("\nError: Unknown operation: %c", symbol);
  }

  return 0;
}
