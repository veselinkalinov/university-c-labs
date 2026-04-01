#include <stdio.h>

int main() {
  double x1, y1, x2, y2, x, y;

  printf("Enter x1: ");
  scanf("%lf", &x1);
  printf("Enter y1: ");
  scanf("%lf", &y1);
  printf("Enter x2: ");
  scanf("%lf", &x2);
  printf("Enter y2: ");
  scanf("%lf", &y2);
  printf("Enter x: ");
  scanf("%lf", &x);
  printf("Enter y: ");
  scanf("%lf", &y);

  if (x >= x1 && x <= x2 && y >= y1 && y <= y2) {
    printf("Inside\n");
  } else {
    printf("Outside\n");
  }

  return 0;
}
