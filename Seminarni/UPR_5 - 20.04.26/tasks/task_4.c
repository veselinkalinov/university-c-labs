#include <stdio.h>
#include <stdlib.h>

int main() {
  char filename[256];
  int key;
  char out[300];
  const char *temp_dir;

  printf("Enter filename: ");
  scanf("%255s", filename);
  printf("Enter key (2-10): ");
  scanf("%d", &key);

  if (key < 2 || key > 10) {
    printf("Key must be between 2 and 10.\n");
    return 1;
  }

  temp_dir = getenv("TEMP");
  if (temp_dir == NULL) {
    temp_dir = ".";
  }

  snprintf(out, sizeof(out), "%s\\out.txt", temp_dir);

  FILE *fin = fopen(filename, "rb");
  if (!fin) {
    printf("Cannot open file: %s\n", filename);
    return 1;
  }

  FILE *fout = fopen(out, "wb");
  if (!fout) {
    printf("Cannot create output file.\n");
    fclose(fin);
    return 1;
  }

  unsigned char buffer[256];
  size_t count;

  while ((count = fread(buffer, 1, sizeof(buffer), fin)) > 0) {
    for (size_t i = 0; i < count; i++) {
      buffer[i] = (unsigned char)(buffer[i] + key);
    }

    if (fwrite(buffer, 1, count, fout) != count) {
      printf("Cannot write to output file.\n");
      fclose(fin);
      fclose(fout);
      return 1;
    }
  }

  fclose(fin);
  fclose(fout);

  printf("Encoded successfully to: %s\n", out);
  return 0;
}
