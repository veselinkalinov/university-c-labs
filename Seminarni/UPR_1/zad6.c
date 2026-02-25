#include <stdio.h>

int main()
{
    int a, b, h;
    printf("Enter side a:\n2");
    scanf("%d", &a);
    printf("Enter side b:\n");
    scanf("%d", &b);
    printf("Enter height h:");
    scanf("%d", &h);

    int s = ((a + b) * h) / 2;
    printf("s = %d", s);
    return 0;
}
