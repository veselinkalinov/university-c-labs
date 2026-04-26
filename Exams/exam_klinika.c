#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[31];
    char chip[8];
    float price;
} Patient;

Patient *addPatient(Patient *arr, int *count)
{
    (*count)++;
    arr = realloc(arr, (*count) * sizeof(Patient));
    if (arr == NULL)
    {
        printf("Realloc Error!!!");
        exit(1);
    }
    Patient *p = &arr[(*count) - 1];
    printf("Name: "); scanf(" %30[^\n]",p->name);
    printf("Chip: "); scanf("%7s", p->chip);
    printf("Price: "); scanf("%f", &p->price);

    FILE *f = fopen("animalsText.txt", "a");
    if (f == NULL)
    {
        printf("File Error!!!");
        exit(1);
    }

    fprintf(f,"%s,%f", p->name,p->price);


    free(f);
    return arr;
}

void nameByPrice(Patient *arr, int count, float price)
{
    int found = 0;
    for (int i = 0; i < count; i++)
    {
        if (arr[i].price == price)
        {
            printf("%s - %s", arr[i].name, arr[i].chip);
            found = 1;
        }
    }

    if (!found)
      printf("No such price");
}

void priceBin(float price)
{
    FILE *f = fopen("animalsBin.bin", "rb");
    if (f==NULL){
        printf("Error!!!");
        exit(1);
    }

    Patient p;
    while (fread(&p, sizeof(Patient), 1, f) == 1) {
      if (p.price >= price) {
        printf("Bin Names: %s\n", p.name);
        printf("Bin chip: %s\n", p.chip);
        printf("Bin Price: %.2f\n", p.price);
        printf("---------------");
        break;
      }
    }

    fclose(f);
}

int main(void)
{
    Patient *arr = NULL;
    int count = 0;
}
