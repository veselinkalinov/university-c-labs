#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int capacity = 4;
  int count = 0;

  int *arr = malloc(capacity * sizeof(int));
  if (arr == NULL) {
    fprintf(stderr, "malloc failed\n");
    return 1;
  }

  // simulate pushing elements beyond initial capacity
  for (int i = 0; i < 8; i++) {
    if (count == capacity) {
      capacity *= 2;

      // store in a temp pointer — do NOT do: arr = realloc(arr, ...)
      int *temp = realloc(arr, capacity * sizeof(int));
      if (temp == NULL) {
        fprintf(stderr, "realloc failed\n");
        free(arr); // original block is still valid, free it
        return 1;
      }
      arr = temp;
    }
    arr[count++] = i * 10;
  }

  for (int i = 0; i < count; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  free(arr);
  return 0;
}
