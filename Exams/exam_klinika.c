#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char name[31];
  char id[8];
  float price;
} Patient;

Patient *zad1(Patient *arr, int *n) {
  (*n)++;
  FILE *ft = fopen("animalsText.txt", "a");
  if (ft == NULL) {
    printf("ft error");
    exit(1);
  }

  arr = realloc(arr, (*n) * sizeof(Patient));
  if (arr == NULL) {
    printf("arr realloc error");
    exit(1);
  }

  Patient *p = &arr[(*n) - 1];
  printf("Name: ");
  scanf("%30[^\n]", p->name);
  printf("Chip ID: ");
  scanf("%7s", p->id);
  printf("Price: ");
  scanf("%f", &p->price);

  fprintf(ft, "%30s,%.2f", p->name, p->price);

  fclose(ft);
  return arr;
}

void zad2(Patient *arr, int n, float price) {
  int found = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i].price == price) {
      printf("%30s - %7s\n", arr[i].name, arr[i].id);
      found = 1;
      break;
    }
  }
  if (!found) {
    printf("price not found\n");
    exit(1);
  }
}

void zad3(float price) {
  FILE *fb = fopen("animalsBin.bin", "rb");
  if (fb == NULL) {
    printf("fb error\n");
    exit(1);
  }

  Patient p;
  while (fread(&p, sizeof(Patient), 1, fb) == 1) {
    if (p.price >= price) {
      printf("Bin OwnerName: %30s\n", p.name);
      printf("Bin Chip: %7s\n", p.id);
      printf("Bin Price: %.2f\n", p.price);
      printf("--------------------------------\n");
    }
  }
  fclose(fb);
}

int main(void) {
  Patient *arr = NULL;
  int n = 0;

  arr = zad1(arr, &n);

  float p = 17.25;
  zad2(arr, n, p);

  zad3(p);

  free(arr);
  return 0;
}
