#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[31];
    char date[8];
    unsigned long long int id;
    float price;
    int quantity;
}Medicine;

Medicine *zad1(Medicine *arr, int *count)
{
    FILE *fb = fopen("medicine.bin", "rb");
    if (fb == NULL)
    {
        printf("fb error");
        exit(1);
    }

    fseek(fb,0,SEEK_END);
    *count = ftell(fb)/sizeof(Medicine);
    fseek(fb,0,SEEK_SET);

    arr = malloc((*count) * sizeof(Medicine));
    if (arr == NULL)
    {
        printf("arr malloc error");
        exit(1);
    }

    fread(arr,sizeof(Medicine),*count,fb);

    fclose(fb);
    return arr;
}

Medicine *zad2(Medicine *arr, int count, char *date, Medicine *result, int *n)
{
    int targetYear, targetMonth;
    sscanf(date, "%d.%d", &targetMonth, &targetYear);

    int found = 0;

    for(int i = 0; i < count; i++)
    {
        int curYear, curMonth;
        sscanf(arr[i].date,"%d.%d",&curMonth,&curYear);
        if (curYear < targetYear || (curYear==targetYear && curMonth < targetMonth))
        {
            (*n)++;
            found = 1;
            result = realloc(result, (*n)*sizeof(Medicine));
            if (result==NULL)
            {
                printf("result realloc error");
                exit(1);
            }

            result[(*n)-1] = arr[i];
        }
    }
    if (!found)
    {
        return NULL;
    }

    return result;
}

int zad3(Medicine *arr, int count, float minPrice, float maxPrice, int *n)
{
    FILE *ft = fopen("offer.txt", "w");
    if (ft == NULL)
    {
        printf("ft error");
        exit(1);
    }

    for (int i = 0; i < count; i++)
    {
        if (arr[i].price >= minPrice && arr[i].price <= maxPrice)
        {
            (*n)++;
            fprintf(ft, "%s\n%s\n%llu\n%.2fleva\n", arr[i].name, arr[i].date, arr[i].id, arr[i].price);

        }
    }

    if (*n == 0)
    {
        return 0;
    }

    fclose(ft);
    return *n;
}

void zad4(Medicine *arr, int *count, char *name, char *date)
{
    int idx = -1;
    for (int i = 0; i < *count; i++)
    {
        if (strcmp(arr[i].name,name) == 0 && strcmp(arr[i].date, date)==0)
        {
            idx = i;
            break;
        }
    }

    if (idx == -1)
    {
        printf("error");
        return;
    }

    for (int i = idx; i < *count - 1; i++){
      arr[i] = arr[i + 1];
     }
     (*count)--;
     arr = realloc(arr, (*count) * sizeof(Medicine));
     printf("Deleted");
}
