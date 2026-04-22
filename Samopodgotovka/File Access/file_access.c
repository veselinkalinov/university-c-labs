#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fh_output = fopen("io.txt","w");

    if (fh_output == NULL){
        printf("Error!!!");
        exit(1);
    }

    //fputs("123\n",fh_output);
    //fputs("abc\n",fh_output);
    //fputs("A string\n",fh_output);

    //int data = 5;
    //fprintf(fh_output,"data: %d\n",data);

    // for (int i = 0; i < 10; i++){
    //     fprintf(fh_output, "Number %d: %d\n",i+1,i);
    // }

    int input = 0;
    while(1){
        printf("Enter # (-1 quits): ");
        scanf("%d",&input);
        if (input == -1) {
            break;
        }
        else
        {
            fprintf(fh_output, "%d\n",input);
        }
    }

    fclose(fh_output);

    FILE *fh_input = fopen("io.txt","r");
    if (fh_input == NULL){
        printf("Error!!!");
        exit(1);
    }

    int finput = 0;
    int lines= 0;
    int numbers[100];

    while (fscanf(fh_input, "%d\n", &finput) != EOF) {
      numbers[lines] = finput;
      printf("file line %d: %d\n", lines+1,finput);
      lines++;
    }

    int total = 0;
    for (int i = 0; i < lines; i++){
        total += numbers[i];
    }
    printf("Average: %d\n", total / lines);

    fclose(fh_input);

    fh_input = fopen("in.txt", "r");

    if (fh_input == NULL){
        printf("Error!!!");
        exit(1);
    }

    char buffer[4098];
    fgets(buffer, sizeof(buffer),fh_input);
    printf("Buffer: %s\n",buffer);
    fclose(fh_input);

    return 0;

}

