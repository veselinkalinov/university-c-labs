#include <stdio.h>

void multof4(int a, int b) {
  if (a > b) {
    for (int i = b; i <= a; i++) {
      if (i % 4 == 0) {
        printf("%d ", i);
      }
    }
  } else {
    for (int i = a; i <= b; i++) {
      if (i % 4 == 0) {
        printf("%d ", i);
      }
    }
  }
}

int main() {
  multof4(3, 27);
  return 0;
}
