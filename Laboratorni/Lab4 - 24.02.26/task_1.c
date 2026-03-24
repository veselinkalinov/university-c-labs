#include <stdio.h>

int sum_array(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int my_array[] = {1, 2, 3, 4, 5};
    int size = sizeof(my_array) / sizeof(my_array[0]);
    
    int result = sum_array(my_array, size);
    printf("The sum of the array elements is: %d\n", result);
    
    return 0;
}
