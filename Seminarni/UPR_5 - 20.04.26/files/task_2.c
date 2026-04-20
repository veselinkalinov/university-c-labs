#include <stdio.h>
#include <string.h>

typedef struct {
  char name[100];
  double price;
  int number;
} Product;

typedef struct {
  char address[100];
  int product_number;
} Order;

Product products[100];
int p_count = 0;

Order waiting[100];
int w_count = 0;

int find_product(int num) {
  for (int i = 0; i < p_count; i++)
    if (products[i].number == num)
      return i;
  return -1;
}

void fulfill_waiting(int num) {
  int idx = find_product(num);
  for (int i = 0; i < w_count; i++) {
    if (waiting[i].product_number == num) {
      printf("Client %s ordered %s\n", waiting[i].address, products[idx].name);
      for (int j = i; j < w_count - 1; j++)
        waiting[j] = waiting[j + 1];
      w_count--;
      i--;
    }
  }
}

int main() {
  char line[200];

  while (fgets(line, sizeof(line), stdin)) {
    line[strcspn(line, "\n")] = '\0';
    if (strcmp(line, "END") == 0)
      break;

    if (strcmp(line, "Product") == 0) {
      Product p;
      char price_line[50], num_line[50];

      printf("Name of product: ");
      fgets(p.name, sizeof(p.name), stdin);
      p.name[strcspn(p.name, "\n")] = '\0';

      printf("Price of %s: \n", p.name);
      fgets(price_line, sizeof(price_line), stdin);
      sscanf(price_line, "%lf", &p.price);

      printf("Number of %s: \n", p.name);
      fgets(num_line, sizeof(num_line), stdin);
      sscanf(num_line, "%d", &p.number);

      products[p_count++] = p;
      fulfill_waiting(p.number);

    } else if (strcmp(line, "Order") == 0) {
      Order o;
      char num_line[50];

      printf("Address of order: ");
      fgets(o.address, sizeof(o.address), stdin);
      o.address[strcspn(o.address, "\n")] = '\0';

      printf("Number of ordered product: ");
      fgets(num_line, sizeof(num_line), stdin);
      sscanf(num_line, "%d", &o.product_number);

      int idx = find_product(o.product_number);
      if (idx != -1) {
        printf("Client %s ordered %s\n", o.address, products[idx].name);
      } else {
        waiting[w_count++] = o;
      }
    }
  }

  return 0;
}
