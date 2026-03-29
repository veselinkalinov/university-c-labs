#include <stdio.h>

char reverse(char str[]) {
  int size = 0;
  while (str[size] != '\0') {
    size++;
  }

  for (int i = 0; i < size / 2; i++) {
    char temp = str[i];
    str[i] = str[size - (i + 1)];
    str[size - (i + 1)] = temp;
  }

  return 0;
}

int main() {
  char arr[] = "Reverse";
  printf("Original array: %s\n", arr);

  reverse(arr);

  printf("Reversed array: %s\n", arr);
  return 0;
}
