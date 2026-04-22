#include <stdio.h>
#include <stdlib.h>

int main(void) {
  // WRITE A FILE

  FILE *pFile = fopen("output.txt", "w");

  char text[] = "RANDOM RANDOM RANDOM\nEVERYWHERE!";

  if (pFile == NULL) {
    printf("Error opening file");
    exit(1);
  }

  fprintf(pFile,"%s",text);

  printf("File was written successfully");

  fclose(pFile);

  return 0;
}
