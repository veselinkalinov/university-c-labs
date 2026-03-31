#include <stdio.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
  printf("%d %d", *a, *b);
}

int main() {
  int a = 10;
  int b = 5;
  swap(&a, &b);
}
