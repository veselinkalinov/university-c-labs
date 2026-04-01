#include <stdio.h>

int main() {
  int n;
  printf("Enter the number of elements: \n");
  scanf("%d", &n);

  int array[n];
  printf("Eneter %d integers: \n", n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &array[i]);
  }

  for (int i = 0; i < n / 2; i++) {
    int temp = array[i];
    array[i] = array[n - 1 - i];
    array[n - 1 - i] = temp;
  }

  printf("Reversed array: \n");
  for (int i = 0; i < n; i++) {
    printf("%d", array[i]);
    if (i < n - 1) {
      printf(" ");
    }
  }
  printf("\n");
  return 0;
}
