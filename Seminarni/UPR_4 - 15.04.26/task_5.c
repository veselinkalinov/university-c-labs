#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *arr = NULL;
    int size = 0;
    int q;

    printf("Enter number of commands: ");
    scanf("%d", &q);

    for (int i = 0; i < q; i++) {
        int command;
        scanf("%d", &command);

        if (command == 1) {
            int x;
            scanf("%d", &x);

            arr = (int *)realloc(arr, (size + 1) * sizeof(int));
            arr[size] = x;
            size++;
        } else if (command == 2) {
            int x;
            int newSize = 0;
            scanf("%d", &x);

            for (int j = 0; j < size; j++) {
                if (arr[j] != x) {
                    arr[newSize] = arr[j];
                    newSize++;
                }
            }

            size = newSize;
            arr = (int *)realloc(arr, size * sizeof(int));
        } else if (command == 3) {
            if (size == 0) {
                printf("The collection is empty.\n");
            } else {
                int min = arr[0];

                for (int j = 1; j < size; j++) {
                    if (arr[j] < min) {
                        min = arr[j];
                    }
                }

                printf("%d\n", min);
            }
        }
    }

    free(arr);
    return 0;
}
