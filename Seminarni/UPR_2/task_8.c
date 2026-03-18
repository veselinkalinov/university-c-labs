#include <stdio.h>

int main() {
  double volume, pipe1, pipe2;
  int hours;

  printf("Enter pool volume (cubic meters): ");
  scanf("%lf", &volume);
  printf("Enter pipe 1 flow rate (liters/hour): ");
  scanf("%lf", &pipe1);
  printf("Enter pipe 2 flow rate (liters/hour): ");
  scanf("%lf", &pipe2);
  printf("Enter hours the worker is away: ");
  scanf("%d", &hours);

  double volumeLiters = volume * 1000;

  double totalWater = (pipe1 + pipe2) * hours;

  if (totalWater <= volumeLiters) {
    printf("The pool is %.0f%% full.\n", (totalWater / volumeLiters) * 100);
    printf("%.1f liters more needed to fill it.\n", volumeLiters - totalWater);
  } else {
    printf("The pool has overflowed!\n");
    printf("%.1f liters have overflowed.\n", totalWater - volumeLiters);
  }

  return 0;
}
