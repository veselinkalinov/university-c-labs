#include <stdio.h>
#include <stdlib.h>

int main(void){
    // READ A FILE

    FILE *pFile = fopen("input.txt","r");
    char buffer[1024] = {0};

    if (pFile == NULL){
        printf("Error reading file\n");
        exit(1);
    }

    while(fgets(buffer, sizeof(buffer),pFile) != NULL){
        printf("%s",buffer);
    }
    fclose(pFile);
    return 0;


}
