#include <stdio.h>

int main() {
  int n;
  printf("Enter number of elelments: ");
  scanf("%d", &n);

  int array[n];
  printf("Enter elements: ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &array[i]);
  }

  int targetSum;
  printf("Enter targetSum:");
  scanf("%d", &targetSum);

  int found = 0;

  for (int i = 0; i < n && !found; i++) {
    int sum = 0;
    for (int j = i; j < n; j++) {
      sum += array[j];
      if (sum == targetSum) {
        for (int k = i; k <= j; k++) {
          printf("%d", array[k]);
          if (k < j) {
            printf(" ");
          }
        }
        printf("\n");
        found = 1;
        break;
      }
    }
  }

  if (!found) {
    printf("There is no such sequence\n");
  }

  return 0;
}
