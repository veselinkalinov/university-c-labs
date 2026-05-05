#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[31];
  char date[8];
  unsigned long long id;
  float price;
  int qty;
} Medicine;

Medicine *zad2(Medicine *arr, int count, char *date) {
  int targetMonth, targetYear;
  sscanf(date, "%d.%d", &targetMonth, &targetYear);

  Medicine *result = NULL;
  int n = 0;
  int curMonth, curYear;

  for (int i = 0; i < count; i++) {
    sscanf(arr[i].date, "%d.%d", &curMonth, &curYear);
    if (curYear < targetYear ||
        (curYear == targetYear && curMonth < targetMonth)) {
      n++;
      result = realloc(result, n * sizeof(Medicine));
      if (result == NULL) {
        return NULL;
      }
      result[n - 1] = arr[i];
    }
  }

  return result;
}

int zad3(Medicine *arr, int count, float minPrice, float maxPrice) {
  FILE *ft = fopen("offer.txt", "w");
  if (ft == NULL) {
    exit(1);
  }

  int counter = 0;

  for (int i = 0; i < count; i++) {
    if (arr[i].price >= minPrice && arr[i].price <= maxPrice) {
      counter++;
      fprintf(ft, "%s\n%s\n%llu\n%.2fleva\n\n", arr[i].name, arr[i].date,
              arr[i].id, arr[i].price);
    }
  }

  fclose(ft);
  return counter;
}

Medicine *zad4(Medicine *arr, int *count, char *name, char *date) {
  int idx = -1;
  for (int i = 0; i < *count; i++) {
    if (strcmp(arr[i].name, name) == 0 && strcmp(arr[i].date, date) == 0) {
      idx = i;
      break;
    }
  }

  if (idx == -1) {
    printf("No such element.");
    exit(1);
  }

  for (int i = idx; i < *count - 1; i++) {
    arr[i] = arr[i + 1];
  }

  (*count)--;
  arr = realloc(arr, (*count) * sizeof(Medicine));
  if (arr == NULL) {
    exit(1);
  }

  return arr;
}

int main(void) {
  // zad.1:
  FILE *fb = fopen("medicines.bin", "rb");
  if (fb == NULL) {
    exit(1);
  }

  Medicine *medicines = NULL;
  Medicine temp;
  int count = 0;

  while (fread(&temp, sizeof(Medicine), 1, fb) == 1) {
    count++;
    medicines = realloc(medicines, count * sizeof(Medicine));
    if (medicines == NULL) {
      exit(1);
    }

    medicines[count - 1] = temp;
  }

  fclose(fb);
  free(medicines);
  return 0;
}
