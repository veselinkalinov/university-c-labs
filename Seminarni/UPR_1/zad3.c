#include <stdio.h>

int main()
{
    double deg;
    printf("Enter degrees:");
    scanf("%lf", &deg);

    double far = (deg * 1.8) + 32;
    printf("%.2f Celsius are %.2f in Fahrenheit", deg, far);
    return 0;
}
