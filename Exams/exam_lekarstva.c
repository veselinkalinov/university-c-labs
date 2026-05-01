#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[31];
    char date[8];
    unsigned long long int code;
    float price;
    int quantity;
}Medicine;

Medicine *addMedicine(Medicine *arr, int *count)
{
    FILE *fb = fopen("medicines.bin", "rb");
    if (fb == NULL)
    {
        printf("File Error");
        exit(1);
    }

    fseek(fb, 0, SEEK_END);
    *count = ftell(fb) / sizeof(Medicine);
    fseek(fb, 0, SEEK_SET);

    arr = malloc((*count) * sizeof(Medicine));
    if (arr == NULL) {
      printf("Alloc Error");
      exit(1);
    }

    fread(arr,sizeof(Medicine),*count,fb);

    fclose(fb);
    return arr;
}

Medicine *expiryDate(Medicine *arr,Medicine *result, int count,char date[8], int *newCount)
{
    int targetMonth, targetYear;
    sscanf(date, "%d.%d", &targetMonth, &targetYear);

    for (int i = 0; i < count; i++)
    {
        int month, year;
        sscanf(arr[i].date, "%d.%d", &month, &year);
        if(targetYear > year || (targetYear == year && targetMonth > month))
        {
            (*newCount)++;
            result = realloc(result,(*newCount)*sizeof(Medicine));
            if (result == NULL)
            {
                printf("Error");
                exit(1);
            }
            result[(*newCount)-1] = arr[i];
        }
        else return NULL;

    }

    return result;
}

int ArrToTxt(Medicine *arr, int count, int minPrice, int maxPrice)
{
    FILE *ft = fopen("offer.txt", "a");
    if (ft == NULL)
    {
        printf("File Error");
        exit(1);
    }

    int elCount = 0;
    for (int i = 0; i < count; i++)
    {
        if (minPrice <= arr[i].price && arr[i].price <= maxPrice)
        {
            elCount++;
            fprintf(ft,"%30s\n%7s\n%llu%.2f leva\n",arr[i].name,arr[i].date,arr[i].code,arr[i].price);

        }
    }

    fclose(ft);
    if (elCount > 0) return elCount;
    else return 0;
}

void delete_medicine(Medicine *arr, int *size, const char *t_name,const char *t_date) {
  int found_index = -1;

  for (int i = 0; i < *size; i++) {
    if (strcmp(arr[i].name, t_name) == 0 &&
        strcmp(arr[i].date, t_date) == 0) {
      found_index = i;
      break;
    }
  }

  if (found_index == -1) {
    printf("Lekarstvoto ne e namereno.\n");
    return;
  }

  for (int i = found_index; i < *size - 1; i++) {
    arr[i] = arr[i + 1];
  }

  (*size)--;

  if (*size > 0) {
    Medicine *temp = realloc(arr, (*size) * sizeof(Medicine));
    if (temp != NULL) {
      arr = temp;
    }
  } else {
    free(arr);
    arr = NULL;
  }

  printf("Lekarstvoto e iztrito uspeshno.\n");
}

int main(void)
{
    Medicine *arr = NULL;
    int count = 0;
    arr = addMedicine(arr, &count);

    Medicine *result = NULL;
    int newCount = 0;
    result = expiryDate(arr,result, count, "12.2026",&newCount);

    free(arr);
    free(result);
    return 0;
}
