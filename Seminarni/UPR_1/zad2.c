#include <stdio.h>

int main()
{
    double inch;
    printf("Inches:");
    scanf("%lf", &inch);

    double mm = inch * 25.4;
    double cm = inch * 2.54;
    double dm = inch * 0.254;
    double m = inch * 0.0254;

    printf("%.4f inches=\n", inch);
    printf("%.4f mm\n", mm);
    printf("%.4f cm\n", cm);
    printf("%.4f dm\n", dm);
    printf("%.4f m\n", m);
}
