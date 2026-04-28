#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[51];
    char date[11];
    int lectures;
    float price;
} Course;

Course *BinToArr(Course *arr, int *n)
{
    FILE *fb = fopen("courses.bin", "rb");
    if (fb == NULL)
    {
        printf("File Error!!!");
        exit(1);
    }

    fread(n, sizeof(int),1,fb);
    arr = malloc((*n)*sizeof(Course));
    fread(arr,sizeof(Course),*n,fb);

    fclose(fb);
    return arr;
}

void ZadTwo(Course *arr, int n, int idx)
{
    if (idx < 0 || idx>= n)
    {
        printf("index error");
        exit(1);
    }

    arr[idx].price = arr[idx].price - (0.1 * arr[idx].price);
    printf("%.2f lv - %50s - %10s", arr[idx].price, arr[idx].name, arr[idx].date);

}

void ArrToText(Course *arr, int n, float minPrice, float maxPrice)
{
    FILE *ft = fopen("offer.txt", "w");
    if (ft == NULL)
    {
        printf("Error!!!");
        exit(1);
    }

    for (int i = 0; i < n; i++)
    {
        if(minPrice >= arr[i].price && arr[i].price <= maxPrice){
            fprintf(ft, "%30s\n%10s\n%d lectures\n%.2f eur.", arr[i].name, arr[i].date, arr[i].lectures, arr[i].price);
        }
    }

    fclose(ft);
}



int main(void)
{
    Course *arr = NULL;
    int n = 0;
    arr = BinToArr(arr, &n);

    for (int i = 0; i < n; i++)
    {
        printf("%50s - %10s - %d - %.2f", arr[i].name, arr[i].date, arr[i].lectures, arr[i].price);
    }


    free(arr);
    return 0;
}
