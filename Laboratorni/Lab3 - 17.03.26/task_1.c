#include <stdio.h>

int compare(int a, int b) {
  if (a > b) {
    return a;
  } else if (b > a) {
    return b;
  } else {
    return a;
  }
}

int main() {
  int res = compare(23, 12);
  printf("%d\n", res);
  return 0;
}
