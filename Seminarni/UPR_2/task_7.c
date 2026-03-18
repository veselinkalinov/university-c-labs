#include <stdio.h>

int main() {
  int n;
  char period;

  printf("Enter kilometers: ");
  scanf("%d", &n);
  printf("Enter peroid for the taxiRate(D/N): ");
  scanf(" %c", &period);

  double taxiRate = (period == 'D') ? 0.79 : 0.90;
  double taxiPrice = 0.70 + n * taxiRate;

  double busPrice = n * 0.09;

  double trainPrice = n * 0.06;

  double cheapest = taxiPrice;

  if (n >= 20 && busPrice < cheapest) {
    cheapest = busPrice;
  }
  if (n >= 100 && trainPrice < cheapest) {
    cheapest = trainPrice;
  }

  printf("Cheapest price: %.2f\n", cheapest);

  return 0;
}
