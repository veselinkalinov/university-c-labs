#include <stdio.h>

int main() {
  int n;
  printf("Enter number of elements: ");
  scanf("%d", &n);

  int arr[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  int bestIncStart = 0, bestIncLen = 1;
  int curIncStart = 0, curIncLen = 1;

  for (int i = 1; i < n; i++) {
    if (arr[i] > arr[i - 1]) {
      curIncLen++;
    } else {
      if (curIncLen > bestIncLen) {
        bestIncLen = curIncLen;
        bestIncStart = curIncStart;
      }
      curIncStart = i;
      curIncLen = 1;
    }
  }
  if (curIncLen > bestIncLen) {
    bestIncLen = curIncLen;
    bestIncStart = curIncStart;
  }

  int bestDecStart = 0, bestDecLen = 1;
  int curDecStart = 0, curDecLen = 1;

  for (int i = 1; i < n; i++) {
    if (arr[i] < arr[i - 1]) {
      curDecLen++;
    } else {
      if (curDecLen > bestDecLen) {
        bestDecLen = curDecLen;
        bestDecStart = curDecStart;
      }
      curDecStart = i;
      curDecLen = 1;
    }
  }
  if (curDecLen > bestDecLen) {
    bestDecLen = curDecLen;
    bestDecStart = curDecStart;
  }

  if (bestIncLen >= bestDecLen) {
    printf("Ascending (length %d): ", bestIncLen);
    for (int i = bestIncStart; i < bestIncStart + bestIncLen; i++) {
      printf("%d ", arr[i]);
    }
  } else {
    printf("Descending (length %d): ", bestDecLen);
    for (int i = bestDecStart; i < bestDecStart + bestDecLen; i++) {
      printf("%d ", arr[i]);
    }
  }
  printf("\n");

  return 0;
}
