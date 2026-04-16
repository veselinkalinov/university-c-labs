#include <stdio.h>
#include <stdlib.h>

int isPrime(int number) {
    if (number < 2) {
        return 0;
    }

    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            return 0;
        }
    }

    return 1;
}

void printArray(int *arr, int size) {
    if (size == 0) {
        printf("(empty)");
    } else {
        for (int i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

int main(void) {
    int n;
    int *original;
    int *withoutPrimes;
    int *primes;
    int withoutPrimesCount = 0;
    int primesCount = 0;

    printf("Enter n: ");
    scanf("%d", &n);

    original = (int *)malloc(n * sizeof(int));
    withoutPrimes = (int *)malloc(n * sizeof(int));
    primes = (int *)malloc(n * sizeof(int));

    printf("Enter the numbers:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &original[i]);

        if (isPrime(original[i])) {
            primes[primesCount] = original[i];
            primesCount++;
        } else {
            withoutPrimes[withoutPrimesCount] = original[i];
            withoutPrimesCount++;
        }
    }

    printf("Array without prime numbers:\n");
    printArray(withoutPrimes, withoutPrimesCount);

    printf("Array with prime numbers:\n");
    printArray(primes, primesCount);

    free(original);
    free(withoutPrimes);
    free(primes);

    return 0;
}
