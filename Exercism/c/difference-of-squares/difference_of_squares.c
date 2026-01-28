#include "difference_of_squares.h"

unsigned int square_of_sum(unsigned int number)
{
    unsigned long long sum = (unsigned long long)number * (number + 1) / 2;
    return (unsigned int)(sum * sum);
}

unsigned int sum_of_squares(unsigned int number)
{
    unsigned long long result = (unsigned long long)number * (number + 1) * (2 * number + 1) / 6;
    return (unsigned int)result;
}

unsigned int difference_of_squares(unsigned int number)
{
    return square_of_sum(number) - sum_of_squares(number);
}
#include "difference_of_squares.h"
