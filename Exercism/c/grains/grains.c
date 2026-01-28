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

uint64_t square(uint8_t index)
{
    if (index < 1 || index > 64)
    {
        return 0;
    }

    return 1ULL << (index - 1);
}

uint64_t total(void)
{
    return ~0ULL;
}
