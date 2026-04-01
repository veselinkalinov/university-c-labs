#include <stdio.h>

int main() {
  int hours, minutes;
  printf("Enter hours and minutes: ");
  scanf("%d %d", &hours, &minutes);

  minutes += 15;

  if (minutes >= 60) {
    minutes -= 60;
    hours++;
  }

  if (hours >= 24) {
    hours = 0;
  }

  printf("%d:%02d\n", hours, minutes);

  return 0;
}
