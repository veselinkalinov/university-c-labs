#include <stdio.h>
int main() {
  FILE *f = fopen("zzz.txt", "wb");
  fputs("XYZ", f);
  fclose(f);
  return 0;
}
