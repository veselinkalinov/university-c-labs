#include <stdio.h>

int main() {
  char symbol;
  int rows;

  printf("Symbol: ");
  scanf(" %c", &symbol);

  printf("Rows: ");
  scanf("%d", &rows);

  for (int i = 1; i <= rows; i++) {
    for (int space = 1; space <= rows - i; space++) {
      printf(" ");
    }
    for (int j = 1; j <= (2 * i - 1); j++) {
      printf("%c", symbol);
    }
    printf("\n");
  }

  return 0;
}
