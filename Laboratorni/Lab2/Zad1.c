#include <stdio.h>

int main() {
  unsigned char a = 1;
  printf("%zu\n", sizeof(char));
  printf("%d\n", ~a);
  printf("%u\n", !a);

  return 0;
}
