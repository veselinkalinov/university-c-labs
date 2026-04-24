#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[56];
    char id[7];
    float price;
    int locker;
} Member;

Member *addMember(Member *arr, int *count)
{
    (*count)++;
    arr = realloc(arr, (*count) * sizeof(Member));
    if (arr == NULL)
    {
        printf("Realloc Error!!!");
        exit(1);
    }

    Member *m = &arr[(*count)-1];
    printf("Name: "); scanf(" %[^\n]",m->name);
    printf("ID: "); scanf("%s", m->id);
    printf("Price: "); scanf("%f", &m->price);
    printf("Locker: "); scanf("%d", &m->locker);

    FILE *f = fopen("membersText.txt", "a");
    if (f == NULL)
    {
        printf("File Error!!!");
        exit(1);
    }

    fprintf(f, "%d;%s;%s;%.2f;%d\n",(int)strlen(m->name),m->name,m->id,m->price,m->locker);

    fclose(f);
    return arr;
}

void findBelowAvg(Member *arr, int count)
{
    float sum = 0;
    for (int i = 0; i < count; i++)
    {
        sum+=arr[i].price;
    }
    float avg = sum/count;

    for (int i = 0; i < count; i++){
        if (arr[i].price < avg){
            printf("%s - %s - %.2f - avg:%.2f\n", arr[i].name, arr[i].id, arr[i].price,avg);
        }
    }
}

void idBin(Member *arr, int count, char *sid)
{
    FILE *f = fopen("members.bin", "wb");
    if (f==NULL)
    {
        printf("Bin File Error!!!");
        exit(1);
    }
    fwrite(arr,sizeof(Member),count,f);
    fclose(f);

    f = fopen("members.bin", "rb");
    if (f==NULL)
    {
      printf("Bin File Error!!!");
      exit(1);
    }

    Member m;
    while(fread(&m,sizeof(Member), 1,f) == 1){
        if (strcmp(m.id, sid) == 0){
            printf("Bin Names: %s\n", m.name);
            printf("Bin ID: %s\n", m.id);
            printf("Bin M_Price: %.2f\n", m.price);
            printf("Bin Locker: %d\n", m.locker);
            break;
        }
    }

    fclose(f);
}



int main(void)
{
    Member *arr = NULL;
    int count = 0;

    arr = addMember(arr,&count);
    arr = addMember(arr, &count);
    arr = addMember(arr, &count);

    findBelowAvg(arr, count);

    char sid[7];
    printf("sid: "); scanf("%6s", sid);
    idBin(arr, count, sid);


    free(arr);
    return 0;
}
