#include <stdio.h>

int main() {
  int n;
  printf("Enter n: ");
  scanf("%d", &n);

  int arr[100];
  printf("Enter array: ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  int curStart = 0;
  int curLen = 1;
  int bestStart = 0;
  int bestLen = 1;

  for (int i = 1; i < n; i++) {
    if (arr[i] == arr[i - 1]) {
      curLen++;
    } else {
      if (curLen > bestLen) {
        bestLen = curLen;
        bestStart = curStart;
      }
      curStart = i;
      curLen = 1;
    }
  }

  if (curLen > bestLen) {
    bestLen = curLen;
    bestStart = curStart;
  }

  for (int i = bestStart; i < bestStart + bestLen; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}
