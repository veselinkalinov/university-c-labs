#include <stdio.h>

int main() {
  int arr[20];
  int size = 10;

  printf("Enter %d numbers: ", size);
  for (int i = 0; i < 10; i++) {
    scanf("%d", &arr[i]);
  }

  int num, pos;
  while (size < 20) {
    scanf("%d", &num);
    if (num == 0)
      break;

    scanf("%d", &pos);

    for (int i = size; i > pos; i--) {
      arr[i] = arr[i - 1];
    }

    arr[pos] = num;
    size++;
  }

  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}
