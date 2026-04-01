#include <stdio.h>

int main() {
  int n;
  printf("Enter number of elements:  ");
  scanf("%d", &n);
  int array[n];

  printf("Enter %d sorted integers: \n", n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &array[i]);
  }

  int best_start = 0;
  int best_length = 1;
  int current_start = 0;
  int current_length = 1;

  for (int i = 1; i < n; i++) {
    if (array[i] == array[i - 1]) {
      current_length++;
    } else {
      if (current_length > best_length) {
        best_length = current_length;
        best_start = current_start;
      }
      current_start = i;
      current_length = 1;
    }
  }
  if (current_length > best_length) {
    best_length = current_length;
    best_start = current_start;
  }
  printf("Longest starts at index %d and has length %d\n", best_start,
         best_length);
  return 0;
}
