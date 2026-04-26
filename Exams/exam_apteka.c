#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[31];
    char expiry[8];
    long long code;
    float price;
    int quantity;
} Medicine;

Medicine *addMedicine(Medicine *arr, int *count)
{

    FILE *f = fopen("medicines.txt", "r");
    if (f == NULL)
    {
        printf("Error!!!");
        exit(1);
    }

    Medicine temp;
    while (fscanf(f,"%30s;%7s;%lld;%f;%d",temp.name,temp.expiry,&temp.code,&temp.price,&temp.quantity) != EOF)
    {
      (*count)++;
      arr = realloc(arr, (*count) * sizeof(Medicine));
      if (arr == NULL) {
        printf("Error!!!");
        exit(1);
      }

      arr[(*count) - 1] = temp;

      printf("Complete!!!");
    }

    fclose(f);
    return arr;
}

void ExpiryDiscount(Medicine *arr, int count, char *date)
{
    for (int i = 0; i < count; i++)
    {
        if(strcmp(arr[i].expiry,date) < 0 )
        {
            float oldPrice = arr[i].price;
            arr[i].price = 0.2 * arr[i].price;
            printf("****************************************\n");
            printf("%s - %s - %.2flv - %.2flv\n", arr[i].name, arr[i].expiry,
                   oldPrice, arr[i].price);
        }
    }
}

void OverQuantity(Medicine *arr, int count, int qty)
{
    FILE *f = fopen("offer.bin", "wb");
    if (f==NULL){
        printf("Error!!!");
        exit(1);
    }

    for (int i = 0; i < count; i++){
        if (arr[i].quantity > qty){
            fwrite(&arr[i],sizeof(Medicine),1,f);
        }
    }

    fclose(f);
}

int main (void)
{
    int count = 0;
    Medicine *medicines = NULL;
}
