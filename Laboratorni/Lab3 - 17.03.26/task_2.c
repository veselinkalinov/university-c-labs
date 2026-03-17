#include <stdio.h>

double bonus(double salary, int months) {
  double bonus = 0;
  if (months >= 36) {
    bonus = salary * 0.15;
  } else if (months >= 18) {
    bonus = salary * 0.1;
  } else if (months >= 6) {
    bonus = salary * 0.005;
  }
  return bonus;
}

int main() {
  double salary = 2345;
  int months = 25;
  double b = bonus(salary, months);
  printf("The bonus is %.2lf, and the salary after bonus is %.2lf\n", b, salary + b);

  return 0;
}
