#include <stdio.h>

int main() {
  double X, Y, Z;
  int workers;

  printf("Enter vineyard area (sq. meters): ");
  scanf("%lf", &X);
  printf("Enter grape yield per sq. meter (kg): ");
  scanf("%lf", &Y);
  printf("Enter desired wine quantity (liters): ");
  scanf("%lf", &Z);
  printf("Enter number of workers: ");
  scanf("%d", &workers);

  double totalGrapes = X * Y;

  double grapesForWine = totalGrapes * 0.40;

  double wineProduced = grapesForWine / 2.5;

  printf("Wine produced: %.2f liters\n", wineProduced);

  if (wineProduced >= Z) {
    printf("Sufficient!\n");
    double remainder = wineProduced - Z;
    double perWorker = remainder / workers;
    printf("Remainder per worker: %.2f liters\n", perWorker);
  } else {
    printf("Not sufficient!\n");
    printf("Deficit: %.2f liters\n", Z - wineProduced);
  }

  return 0;
}
