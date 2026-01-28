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
    // Basic validation: A chessboard only has 64 squares.
    if (index < 1 || index > 64)
    {
        return 0;
    }

    /* * We use 1ULL (1 as an Unsigned Long Long) to ensure 64-bit precision.
     * Shifting 1 left by (index - 1) is mathematically equal to 2^(index-1).
     */
    return 1ULL << (index - 1);
}

/**
 * Calculates the total number of grains on all 64 squares.
 * The sum of a power-of-two series (2^0 + ... + 2^n) is (2^(n+1) - 1).
 */
uint64_t total(void)
{
    /* * For 64 squares, the sum is 2^64 - 1.
     * This value is the maximum possible value for a uint64_t.
     * In C, ~0ULL (bitwise NOT on 0) flips all 64 bits to 1,
     * which represents 18,446,744,073,709,551,615.
     */
    return ~0ULL;
}
