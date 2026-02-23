#include <stdio.h>
#include "difference_of_squares.h"

int main()
{
    unsigned int n;

    printf("Enter a natural number (N): ");
    if (scanf("%u", &n) != 1)
    {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    printf("\nResults for N = %u:\n", n);
    printf("Square of the sum:  %u\n", square_of_sum(n));
    printf("Sum of the squares: %u\n", sum_of_squares(n));
    printf("Difference:         %u\n", difference_of_squares(n));

    return 0;
}

unsigned int square_of_sum(unsigned int number)
{

    unsigned long long n = number;
    unsigned long long sum = (n * (n + 1)) / 2;
    unsigned long long result = sum * sum;

    return (unsigned int)result;
}

unsigned int sum_of_squares(unsigned int number)
{
    unsigned long long n = number;
    unsigned long long result = (n * (n + 1) * (2 * n + 1)) / 6;

    return (unsigned int)result;
}

unsigned int difference_of_squares(unsigned int number)
{
    return square_of_sum(number) - sum_of_squares(number);
}
