#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[56];
  char id[7];
  float price;
  int locker;
} Fitness;

Fitness *zad1(Fitness *arr, int *count) {
  (*count)++;
  FILE *ft = fopen("membersText.txt", "a");
  if (ft == NULL) {
    printf("ft error\n");
    exit(1);
  }

  arr = realloc(arr, (*count) * sizeof(Fitness));
  if (arr == NULL) {
    printf("arr realloc error\n");
    exit(1);
  }

  Fitness *f = &arr[(*count) - 1];
  printf("Full Name: ");
  scanf("%55[^\n]", f->name);
  printf("ID: ");
  scanf("%6s", f->id);
  printf("Price: ");
  scanf("%f", &f->price);
  printf("Locker Code (example: 123): ");
  scanf("%d", &f->locker);

  fprintf(ft, "%d;%55s;%6s;%.2f;%d\n", (int)strlen(f->name), f->name, f->id,
          f->price, f->locker);

  fclose(ft);
  return arr;
}

void zad2(Fitness *arr, int count) {
  float sum = 0;
  float avg = 0;
  for (int i = 0; i < count; i++) {
    sum += arr[i].price;
  }

  avg = sum / count;
  for (int i = 0; i < count; i++) {
    if (arr[i].price < avg) {
      printf("%55s - %6s - %.2f\n", arr[i].name, arr[i].id, arr[i].price);
    }
  }
}

void zad3(char *id) {
  FILE *fb = fopen("members.bin", "rb");
  if (fb == NULL) {
    printf("fb error");
    exit(1);
  }

  Fitness *f;
  while (fread(f, sizeof(Fitness), 1, fb) == 1) {
    if (strcmp(f->id, id) == 0) {
      printf("Bin Names: %55s\n", f->name);
      printf("Bin ID: %6s\n", f->id);
      printf("Bin M_Price: %.2f\n", f->price);
      printf("Bin Locker: %d\n", f->locker);
      break;
    }
  }

  fclose(fb);
}

int main(void) {
  Fitness *arr = NULL;
  int count = 0;

  arr = zad1(arr, &count);

  zad2(arr, count);

  char *id = {"AA1234"};
  zad3(id);

  free(arr);
  return 0;
}
