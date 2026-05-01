#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[31];
  char expiry[8];
  unsigned long long int code;
  float price;
  int quantity;
} Medicine;

Medicine *addMedicine(Medicine *arr, int *count) {
  FILE *ft = fopen("medicines.txt", "r");
  if (ft == NULL) {
    printf("File Error");
    exit(1);
  }

  Medicine m;
  while (fscanf(ft, "%30[^;];%7[^;];%llu;%f;%d", m.name, m.expiry, &m.code,
                &m.price, &m.quantity) == 5) {
    (*count)++;
    arr = realloc(arr, (*count) * sizeof(Medicine));
    if (arr == NULL) {
      printf("Alloc Error!!!");
      exit(1);
    }
    arr[(*count) - 1] = m;
  }

  fclose(ft);
  return arr;
}

void discount(Medicine *arr, int count, char date[8]) {
  int found = 0;

  int targetMonth, targetYear;
  sscanf(date, "%d.%d", &targetMonth, &targetYear);

  for (int i = 0; i < count; i++) {
    int medMonth, medYear;
    sscanf(arr[i].expiry, "%d.%d", &medMonth, &medYear);

    if (medYear < targetYear ||
        (medYear == targetYear && medMonth < targetMonth)) {
      float oldPrice = arr[i].price;
      arr[i].price *= 0.8;
      printf("*********************************************\n");
      printf("%30s - %7s - %.2flv %.2flv", arr[i].name, arr[i].expiry, oldPrice,
             arr[i].price);
      found = 1;
    }
  }
  if (!found)
    printf("No such medicine\n");
}

void overqty(Medicine *arr, int count, int qty) {
  FILE *fb = fopen("offer.bin", "wb");
  if (fb == NULL) {
    printf("File Error");
    exit(1);
  }

  for (int i = 0; i < count; i++) {
    if (arr[i].quantity > qty) {
      fwrite(&arr[i], sizeof(Medicine), 1, fb);
    }
  }

  fclose(fb);
}

Medicine *delMed(Medicine *arr, int *count, unsigned long long int code) {
  int found = 0;
  int idx;
  for (int i = 0; i < *count; i++) {
    if (arr[i].code == code) {
      idx = i;
      found = 1;
      break;
    }
  }
  if (!found) {
    printf("No such code found");
    return 0;
  }
  for (int i = idx; i < *count - 1; i++) {
    arr[i] = arr[i + 1];
  }
  (*count)--;
  arr = realloc(arr, (*count) * sizeof(Medicine));
  return arr;
}
