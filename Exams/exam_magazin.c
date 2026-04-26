#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[31];
    int id;
    char expiry[11];
    float price;
} Shop;

Shop *addProduct(Shop *arr, int *count)
{
    (*count)++;
    arr = realloc(arr, (*count) * sizeof(Shop));
    if (arr == NULL)
    {
        printf("Realloc Error!!!");
        exit(1);
    }

    FILE *f = fopen("in.bin", "ab");
    if (f == NULL)
    {
        printf("File Error!!!");
        exit(1);
    }

    Shop *s = &arr[(*count)-1];
    printf("Name: "); scanf("%30s", (*s).name);
    printf("ID: "); scanf("%d", &(*s).id);
    printf("Expiry: "); scanf("%10s", (*s).expiry);
    printf("Price: "); scanf("%f", &(*s).price);

    fwrite(s, sizeof(Shop),1,f);

    fclose(f);
    return arr;
}

Shop *greaterPrice(Shop *arr, int count, float price, int *newCount)
{
    Shop *newArr = NULL;

    for (int i = 0; i < count; i++)
    {
        if (arr[i].price > price)
        {
            (*newCount)++;
            newArr = realloc(newArr, (*newCount) * sizeof(Shop));
            if (newArr == NULL)
            {
                printf("Realloc Error!!!");
                exit(1);
            }
            newArr[*(newCount) - 1] = arr[i];
        }
    }

    return newArr;
}

void BinToTxt()
{
    FILE *fb = fopen("in.bin", "rb");
    if (fb == NULL){
        printf("File Error!!!");
        exit(1);
    }

    FILE *ft = fopen("outTxt.txt", "w");
    if (ft == NULL)
    {
        printf("File Error!!!");
        exit(1);
    }

    Shop p;

    while(fread(&p, sizeof(Shop), 1, fb) == 1){
      printf("Binary Item:\n");
      printf("Name: %s\n", p.name);
      printf("ID: %d\n", p.id);
      printf("Expire Date: %s\n", p.expiry);
      printf("Price: %.2f\n", p.price);
      fprintf(ft, "%s;%d;%s;%.2f\n", p.name, p.id, p.expiry, p.price);
    }
    fclose(ft);fclose(fb);

    ft = fopen("outTxt.txt", "r");
    if (ft == NULL){
        printf("File Error");
        exit(1);
    }
    char name[31];
    int id;
    char expiry[11];
    float price;
    while (fscanf(ft, "%30[^;];%d;%10[^;];%f\n", name, &id, expiry, &price) ==
           4) {
      printf("Text Item:\n");
      printf("Name: %s\n", name);
      printf("ID: %d\n", id);
      printf("Expire Date: %s\n", expiry);
      printf("Price: %.2f\n", price);
      printf("----------------\n");
    }

    fclose(ft);
}

int main(void)
{
    Shop *arr = NULL;
    int count = 0;

    arr = addProduct(arr, &count);
    arr = addProduct(arr, &count);

    int newCount = 0;
    Shop *newArr = greaterPrice(arr, count, 15.0f, &newCount);
    for (int i = 0; i < newCount; i++){
        printf("%s - %d - %s - %.2f", newArr[i].name,newArr[i].id,newArr[i].expiry,newArr[i].price);
    }


    BinToTxt();

    free(newArr);
    free(arr);
    return 0;
}

