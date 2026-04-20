#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int size = 10;
    int *arr = (int *)malloc(size * sizeof(int));

    printf("Enter 10 numbers:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    while (1) {
        int value;
        int index;

        scanf("%d", &value);
        if (value == 0) {
            break;
        }

        scanf("%d", &index);

        if (index < 0) {
            index = 0;
        }
        if (index > size) {
            index = size;
        }

        arr = (int *)realloc(arr, (size + 1) * sizeof(int));

        for (int i = size; i > index; i--) {
            arr[i] = arr[i - 1];
        }

        arr[index] = value;
        size++;
    }

    printf("Result:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}
