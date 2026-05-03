#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[51];
  char date[11];
  int lectures;
  float price;
} Course;

void zad2(Course *arr, int n, int idx) {
  if (idx < 0 || idx > (n - 1)) {
    printf("idx: %d is not in the array", idx);
    exit(1);
  }

  for (int i = 0; i < n; i++) {
    if (idx == i) {
      arr[i].price *= 0.9f;
      printf("%.2f - %50s - %10s", arr[i].price, arr[i].name, arr[i].date);
      break;
    }
  }
}

int zad3(Course *arr, int n, float minPrice, float maxPrice) {
  FILE *ft = fopen("offer.txt", "w");
  if (ft == NULL) {
    printf("File Error");
    exit(1);
  }

  int count = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i].price >= minPrice && arr[i].price <= maxPrice) {
      count++;
      fprintf(ft, "%30s\n%10s\n%d lectures\n%.2f eur.", arr[i].name,
              arr[i].date, arr[i].lectures, arr[i].price);
    }
  }

  if (count == 0) {
    return 0;
  }

  return count;
  fclose(ft);
}

Course *zad4(Course *arr, int *n, char *name, char *date) {
  int idx = -1;
  for (int i = 0; i < *n; i++) {
    if (strcmp(arr[i].name, name) == 0 && strcmp(arr[i].date, date) == 0) {
      idx = i;
      break;
    }
  }

  if (idx == -1) {
    return 0;
  }

  while (idx < (*n) - 1) {
    idx++;
    arr[idx] = arr[idx + 1];
    (*n)--;
    arr = realloc(arr, (*n) * sizeof(Course));
    if (arr == NULL) {
      printf("Realloc Error");
      exit(1);
    }
  }

  return arr;
}

int main(void) {
  Course *arr = NULL;
  int n = 0;
  FILE *fb = fopen("courses.bin", "rb");
  if (fb == NULL) {
    printf("File Error");
    exit(1);
  }

  if (fread(&n, sizeof(int), 1, fb) != 1) {
    printf("Fread error");
    fclose(fb);
    exit(1);
  }

  arr = malloc(n * sizeof(Course));
  if (arr == NULL) {
    printf("Malloc Error");
    fclose(fb);
    exit(1);
  }

  if (fread(arr, sizeof(Course), n, fb) != 1) {
    printf("Fread Error");
    fclose(fb);
    free(arr);
    exit(1);
  }

  fclose(fb);
  free(arr);
  return 0;
}
