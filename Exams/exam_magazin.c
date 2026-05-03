#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[31];
  int id;
  char expiry[11];
  float price;
} Product;

Product *zad1(Product *arr, int *count) {
  (*count)++;
  arr = realloc(arr, (*count) * sizeof(Product));
  if (arr == NULL) {
    printf("arr realloc error");
    exit(1);
  }

  Product *p = &arr[(*count) - 1];
  printf("-----Product %d------\n", *count);
  printf("Product Name: ");
  scanf("%30[^\n]", p->name);
  printf("Product ID: ");
  scanf("%d", &p->id);
  printf("Product Expiry Date: ");
  scanf("%10s", p->expiry);
  printf("Product Price: ");
  scanf("%f", &p->price);

  FILE *fb = fopen("in.bin", "ab");
  if (fb == NULL) {
    printf("fb file error");
    exit(1);
  }
  fwrite(p, sizeof(Product), 1, fb);

  fclose(fb);
  return arr;
}

Product *zad2(Product *arr, int count, int *n, Product *result, float price) {
  for (int i = 0; i < count; i++) {
    if (arr[i].price > price) {
      (*n)++;
      result = realloc(result, (*n) * sizeof(Product));
      if (result == NULL) {
        printf("result realloc error");
        exit(1);
      }
      result[(*n) - 1] = arr[i];
    }
  }

  return result;
}

void zad3() {
  FILE *fb = fopen("in.bin", "rb");
  if (fb == NULL) {
    printf("fb error");
    exit(1);
  }

  FILE *ft = fopen("outTxt.txt", "w");
  if (ft == NULL) {
    printf("ft error");
    exit(1);
  }

  Product p;
  while (fread(&p, sizeof(Product), 1, fb) == 1) {
    printf("Binary Item:\n");
    printf("Name: %s\n", p.name);
    printf("ID: %d\n", p.id);
    printf("Expire Date: %s\n", p.expiry);
    printf("Price: %.2f\n", p.price);
    fprintf(ft, "%s;%d;%s;%.2f\n", p.name, p.id, p.expiry, p.price);
  }
  fclose(fb);
  fclose(ft);

  ft = fopen("outTxt.txt", "r");
  if (ft == NULL) {
    printf("ft error");
    exit(1);
  }
  char name[31];
  int id;
  char expiry[11];
  float price;
  while (fscanf(ft, "%s;%d;%s;%f\n", name, &id, expiry, &price) == 4) {
    printf("Text Item:\n");
    printf("Name: %s\n", name);
    printf("ID: %d\n", id);
    printf("Expire Date: %s\n", expiry);
    printf("Price: %.2f\n", price);
    printf("----------------\n");
  }

  fclose(ft);
}

int main(void) {
  Product *arr = NULL;
  Product *result = NULL;
  int count = 0;
  int n = 0;

  arr = zad1(arr, &count);

  float p = 10.55;
  result = zad2(arr, count, &n, result, p);
  for (int i = 0; i < n; i++) {
    printf("Product %d\n", n);
    printf("Name: %30s\n", result[i].name);
    printf("ID: %d\n", result[i].id);
    printf("Expiry: %10s", result[i].expiry);
    printf("Price: %.2f", result[i].price);
  }

  free(result);
  free(arr);
  return 0;
}
