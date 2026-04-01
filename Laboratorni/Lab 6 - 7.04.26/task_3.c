#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int n = 7;
  int *arr = (int *)malloc(n * sizeof(int));
  if (arr == NULL) {
    exit(1);
  }

  printf("Enter %d numbers [-5000..5000]:\n", n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
  }

  double avg = (double)sum / n;
  printf("Avg: %.2f\n", avg);

  free(arr);
  return 0;
}
