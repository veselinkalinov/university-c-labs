#include <stdio.h>

int main()
{
    double inch;
    printf("Inches:");
    scanf("%f", &inch);

    double mm = inch * 25.4;
    double cm = inch * 2.54;
    double dm = inch * 0.254;
    double m = inch * 0.0254;

    printf("%4f inches", inch);
    printf("%4f mm", mm);
    printf("%4f cm", cm);
    printf("%4f dm", dm);
    printf("%4f m", m);
}
