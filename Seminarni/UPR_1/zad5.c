#include <stdio.h>

int main()
{
    int bgn;
    printf("Enter BGN:");
    scanf("%d", &bgn);

    double usd = bgn * 0.61;
    printf("%d BGN is %.2lf USD", bgn, usd);
    return 0;
}
