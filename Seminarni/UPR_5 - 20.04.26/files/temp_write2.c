#include <stdio.h>
int main() {
  FILE *f = fopen("C:\\Users\\vesko\\AppData\\Local\\Temp\\zzz\.txt", "wb");
  fputs("XYZ", f);
  fclose(f);
  return 0;
}
