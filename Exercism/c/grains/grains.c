#include "grains.h"
#include <stdio.h>
#include <stdint.h>

int main()
{
    unsigned int n;

    printf("Square Num (1-64): ");
    if (scanf("%u", &n) != 1)
        return 1;

    printf("\nResults for square %u:\n", n);

    printf("Grains on this square: %llu\n", square((uint8_t)n));

    printf("Total grains on the whole board: %llu\n", total());

    return 0;
}
