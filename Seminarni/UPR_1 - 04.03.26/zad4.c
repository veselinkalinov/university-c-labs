#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

int main()
{
    double deg;
    printf("Enter degrees:");
    scanf("%lf", &deg);

    double rad = deg * (M_PI / 180);
    printf("%.2lf degrees are %.2f radians", deg, rad);
    return 0;
}
