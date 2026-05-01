#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    unsigned long long id;
    char date[11];
    char name[31];
    char diagnosis[51];
}Treatment;

int count_treatment(Treatment *arr, int n,char *name, char *diagnosis)
{
    int found = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {

      if (strcmp(arr[i].diagnosis, diagnosis) == 0 &&
          strcmp(arr[i].name, name) == 0) {
        count++;
        found = 1;
      }
    }
    if (!found)
    {
        return 0;
    }

    return count;
}

Treatment *add_new_treatment(Treatment *arr,int *n)
{
    (*n)++;
    arr = realloc(arr,(*n)*sizeof(Treatment));
    if (arr == NULL)
    {
        printf("Alloc Error");
        exit(1);
    }

    Treatment *t = &arr[(*n)-1];
    printf("Name: "); scanf("%30[^\n]", t->name);
    printf("Diagnosis: "); scanf("%50[^\n]",t->diagnosis);
    printf("Date: "); scanf("%10s", t->date);
    printf("ID: "); scanf("%llu", &t->id);

    return arr;
}

int write_text_file(Treatment *arr, int n, char *diagnosis)
{
    FILE *ft = fopen("illness.txt", "w");
    if (ft == NULL)
    {
        printf("File Error");
        exit(1);
    }
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (strcmp(arr[i].diagnosis,diagnosis)==0)
        {
            count++;
            fprintf(ft,"Bolnichen prestoi na %30s\nza lechenie na %50s;\n%10s",arr[i].name, arr[i].diagnosis, arr[i].date);

        }
    }
    fclose(ft);
    if (count == 0)
    {
        return 0;
    }

    return count;
}

int main(void)
{
    FILE *fb = fopen("history.bin", "rb");
    if (fb == NULL)
    {
        printf("File Error");
        exit(1);
    }

    int n;
    if (fread(&n, sizeof(int), 1, fb) != 1) {
      printf("File read error");
      fclose(fb);
      exit(1);
    }

    Treatment *arr = NULL;
    arr = malloc(n * sizeof(Treatment));
    if (arr == NULL)
    {
        printf("Malloc Error");
        exit(1);
    }
    if (fread(arr, sizeof(Treatment), n, fb) != n) {
      printf("File read error");
      fclose(fb);
      free(arr);
      exit(1);
    }
    fclose(fb);
    free(arr);
    return 0;
}
