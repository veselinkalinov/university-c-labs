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
  FILE *fb = fopen("task2.bin", "wb");
  if (fb == NULL) {
    printf("Error: cannot create task2.bin\n");
    exit(1);
  }

  int arr[100];
  int n = 0;
  int x;

  printf("Enter integers (0 to stop):\n");
  while (1) {
    printf("Number: ");
    scanf("%d", &x);
    if (x == 0)
      break;
    arr[n] = x;
    fwrite(&arr[n], sizeof(int), 1, fb);
    n++;
  }
  fclose(fb);
  printf("File 'task2.bin' created (%d numbers).\n\n", n);

  int even = 0, odd = 0;

  for (int i = 0; i < n; i++) {
    x = arr[i];
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

  FILE *ft = fopen("task2_sorted.txt", "w");
  if (ft == NULL) {
    printf("Error: cannot create task2_sorted.txt\n");
    exit(1);
  }

  for (int i = 0; i < n; i++) {
    fprintf(ft, "%d\n", arr[i]);
  }
  fclose(ft);
  printf("Sorted array written to 'task2_sorted.txt'.\n");

  return 0;
}
