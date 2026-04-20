#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *arr, int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - 1 - i; j++) {
      if (arr[j] > arr[j + 1]) {
        int tmp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = tmp;
      }
    }
  }
}

int main() {
  FILE *fb = fopen("task1.bin", "wb");
  if (fb == NULL) {
    printf("Error: cannot create task1.bin\n");
    exit(1);
  }

  int n;
  printf("Enter N: ");
  scanf("%d", &n);
  fwrite(&n, sizeof(int), 1, fb);

  int arr[100];
  for (int i = 0; i < n; i++) {
    printf("Enter number %d: ", i + 1);
    scanf("%d", &arr[i]);
    fwrite(&arr[i], sizeof(int), 1, fb);
  }
  fclose(fb);
  printf("File 'task1.bin' created.\n\n");

  int even = 0, odd = 0;

  for (int i = 0; i < n; i++) {
    int x = arr[i];
    if (x < 0)
      x = -x;

    if (x == 0) {
      even++;
      continue;
    }

    while (x > 0) {
      int digit = x % 10;
      if (digit % 2 == 0)
        even++;
      else
        odd++;
      x /= 10;
    }
  }

  printf("Even digits: %d\n", even);
  printf("Odd digits:  %d\n\n", odd);

  bubble_sort(arr, n);

  FILE *ft = fopen("task1_sorted.txt", "w");
  if (ft == NULL) {
    printf("Error: cannot create task1_sorted.txt\n");
    exit(1);
  }

  for (int i = 0; i < n; i++) {
    fprintf(ft, "%d\n", arr[i]);
  }
  fclose(ft);
  printf("Sorted array written to 'task1_sorted.txt'.\n");

  return 0;
}
