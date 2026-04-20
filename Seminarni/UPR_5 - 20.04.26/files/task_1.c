#include <stdio.h>
#include <string.h>

int main() {
  int guests;
  printf("Enter number of guests: ");
  scanf("%d", &guests);

  int bought_tables = 0, bought_chairs = 0, bought_cups = 0, bought_dishes = 0;
  int total_cents = 0;

  char line[100];
  while (fgets(line, sizeof(line), stdin)) {
    line[strcspn(line, "\n")] = '\0';
    if (strcmp(line, "PARTY!") == 0)
      break;
    if (strcmp(line, "Table") == 0) {
      bought_tables++;
      total_cents += 4200;
    } else if (strcmp(line, "Chair") == 0) {
      bought_chairs++;
      total_cents += 1399;
    } else if (strcmp(line, "Cups") == 0) {
      bought_cups++;
      total_cents += 598;
    } else if (strcmp(line, "Dishes") == 0) {
      bought_dishes++;
      total_cents += 2102;
    }
  }

  int need_tables = (guests + 7) / 8;
  int need_chairs = guests;
  int need_cups = (guests + 5) / 6;
  int need_dishes = (guests + 5) / 6;

  int diff_tables = need_tables - bought_tables;
  int diff_chairs = need_chairs - bought_chairs;
  int diff_cups = need_cups - bought_cups;
  int diff_dishes = need_dishes - bought_dishes;

  if (diff_tables < 0)
    diff_tables = 0;
  if (diff_chairs < 0)
    diff_chairs = 0;
  if (diff_cups < 0)
    diff_cups = 0;
  if (diff_dishes < 0)
    diff_dishes = 0;

  printf("%d,%02d\n", total_cents / 100, total_cents % 100);

  if (diff_tables > 0)
    printf("%d %s\n", diff_tables, diff_tables == 1 ? "Table" : "Tables");
  if (diff_chairs > 0)
    printf("%d %s\n", diff_chairs, diff_chairs == 1 ? "Chair" : "Chairs");
  if (diff_cups > 0)
    printf("%d Cups\n", diff_cups);
  if (diff_dishes > 0)
    printf("%d Dishes\n", diff_dishes);

  return 0;
}
