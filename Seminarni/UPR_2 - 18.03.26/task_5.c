#include <stdio.h>

int main() {
  int min = 0;
  int s1, s2, s3;
  printf("Enter seconds of the three competitors: ");
  int count = scanf("%d %d %d", &s1, &s2, &s3);
  int secs = s1 + s2 + s3;

  if (count != 3) {
    printf("Error: More than three competitors!!!");
  }

  while (secs >= 60) {
    secs -= 60;
    min += 1;
  }

  printf("%d:%02d\n", min, secs);

  return 0;
}
