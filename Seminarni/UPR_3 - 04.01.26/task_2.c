#include <stdio.h>

int main() {
  int n;
  printf("Enter number of elements: \n");
  scanf("%d", &n);

  int array[n];
  printf("Enter %d sorted integers: \n", n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &array[i]);
  }

  int is_valid = 1;
  for (int i = 0; i < n - 1; i++) {
    if (i % 2 == 0) {
      if (!(array[i] < array[i + 1])) {
        is_valid = 0;
        break;
      }
    } else {
      if (!(array[i] > array[i + 1])) {
        is_valid = 0;
        break;
      }
    }
  }

  if (is_valid) {
    printf("The array satisfies the rule\n");
  } else {
    printf("The array doesn't satisfy the rule\n");
  }
  return 0;
}
