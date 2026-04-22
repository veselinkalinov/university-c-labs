#include <stdio.h>
#include <string.h>

typedef struct {
  char name[50];
  double price;
  int number;
} Product;

typedef struct {
  char address[50];
  int product_number;
} Order;

Product products[100];
int p_count = 0;

Order waiting[100];
int w_count = 0;

int main() {
  char command[20];

  while (scanf("%19s", command) == 1) {
    if (strcmp(command, "END") == 0)
      break;

    if (strcmp(command, "Product") == 0) {
      Product p;

      scanf("%49s", p.name);
      scanf("%lf", &p.price);
      scanf("%d", &p.number);

      products[p_count++] = p;

      for (int i = 0; i < w_count;) {
        if (waiting[i].product_number == p.number) {
          printf("Client %s ordered %s\n", waiting[i].address, p.name);

          for (int j = i; j < w_count - 1; j++) {
            waiting[j] = waiting[j + 1];
          }

          w_count--;
        } else {
          i++;
        }
      }

    } else if (strcmp(command, "Order") == 0) {
      Order o;
      int found = 0;

      scanf("%49s", o.address);
      scanf("%d", &o.product_number);

      for (int i = 0; i < p_count; i++) {
        if (products[i].number == o.product_number) {
          printf("Client %s ordered %s\n", o.address, products[i].name);
          found = 1;
          break;
        }
      }

      if (!found) {
        waiting[w_count++] = o;
      }
    }
  }

  return 0;
}
