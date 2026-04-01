#include <stdio.h>
#include <stdlib.h>

int main() {
  int multiplier, count;
  printf("Enter mult and count: ");
  scanf("%d %d", &multiplier, &count);

  int *arr = (int *)malloc(count * sizeof(int));
  if (arr == NULL) {
    fprintf(stderr, "malloc error\n");
    return 1;
  }

  for (int i = 0; i < count; i++) {
    arr[i] = multiplier * (i + 1);
  }

  for (int i = 0; i < count; i++) {
    printf("%d", arr[i]);
    if (i < count - 1)
      printf(", ");
  }
  printf("\n");

  free(arr);
  return 0;
}
