#include <stdio.h>

int main() {
  int arr2[5];
  int len = sizeof(arr2) / sizeof(int);
  for (int i = 0; i < len; i++) {
    printf("Element %d\n", i + 1);
    scanf("%d", &arr2[i]);
    printf("%d\n", arr2[i]);
  }
  scanf("%d", arr2[0]);

  printf("%d\n", arr2[0]);
  return 0;
}
