#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    FILE *fin = fopen("input.txt", "r");
    if (!fin) {
        printf("Cannot open input.txt\n");
        return 1;
    }

    char **arr = NULL;
    int count = 0;
    char last_char = '\0';
    int first = 1;

    char word[51];
    int wlen = 0;
    int c;

    while ((c = fgetc(fin)) != EOF) {
        if (c == ' ' || c == '\n' || c == '\r' || c == '\t') {
            if (wlen > 0) {
                word[wlen] = '\0';

                if (first || tolower((unsigned char)word[0]) == tolower((unsigned char)last_char)) {
                    arr = realloc(arr, (count + 1) * sizeof(char *));
                    arr[count] = malloc(strlen(word) + 1);
                    strcpy(arr[count], word);
                    count++;
                    last_char = word[wlen - 1];
                    first = 0;
                }

                wlen = 0;
            }
        } else {
            if (wlen < 50) word[wlen++] = (char)c;
        }
    }
    /* handle last word if no trailing whitespace */
    if (wlen > 0) {
        word[wlen] = '\0';
        if (first || tolower((unsigned char)word[0]) == tolower((unsigned char)last_char)) {
            arr = realloc(arr, (count + 1) * sizeof(char *));
            arr[count] = malloc(strlen(word) + 1);
            strcpy(arr[count], word);
            count++;
        }
    }
    fclose(fin);

    FILE *fbin = fopen("output.bin", "wb");
    if (!fbin) {
        printf("Cannot open output.bin\n");
        return 1;
    }
    for (int i = 0; i < count; i++) {
        fwrite(arr[i], 1, strlen(arr[i]), fbin);
        if (i < count - 1) {
            char space = ' ';
            fwrite(&space, 1, 1, fbin);
        }
    }
    fclose(fbin);

    printf("Contents of output.bin:\n");
    fbin = fopen("output.bin", "rb");
    while ((c = fgetc(fbin)) != EOF) {
        printf("%c", (char)c);
    }
    printf("\n");
    fclose(fbin);

    for (int i = 0; i < count; i++) free(arr[i]);
    free(arr);

    return 0;
}
