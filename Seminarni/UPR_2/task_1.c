#include <stdio.h>

int max(int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}

int min(int a, int b) {
  if (a < b) {
    return a;
  }
  return b;
}

int main() {
  int num;
  int maxVal, minVal;
  int first = 1;

  printf("Enter numbers (0 to stop): ");

  while (1) {
    scanf("%d", &num);

    if (num == 0) {
      break;
    }

    if (first) {
      maxVal = num;
      minVal = num;
      first = 0;
    } else {
      maxVal = max(maxVal, num);
      minVal = min(minVal, num);
    }
  }

  if (first) {
    printf("No numbers were entered.\n");
  } else {
    printf("Max: %d\n", maxVal);
    printf("Min: %d\n", minVal);
  }

  return 0;
}
