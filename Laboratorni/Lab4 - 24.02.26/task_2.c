#include <stdio.h>

int count(char str[]) {
  int count = 0;
  for (int i = 0; str[i] != '\0'; i++) {
    if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z') ||
        (str[i] >= '0' && str[i] <= '9')) {
      count++;
    }
  }

  return count;
}

int main() {
  char string[100];
  int result;
  printf("Enter a string:");
  scanf("%99s", string);
  result = count(string);

  printf("There are %d letters and numbers in the string.\n", result);

  return 0;
}
