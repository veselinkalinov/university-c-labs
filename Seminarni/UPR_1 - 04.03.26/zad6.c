#include <stdio.h>

int main()
{
    int a, b, h;
    printf("Enter side a:");
    scanf("%d", &a);
    printf("\nEnter side b:");
    scanf("%d", &b);
    printf("\nEnter height h:");
    scanf("%d", &h);

    int s = ((a + b) * h) / 2;
    printf("s = %d", s);
    return 0;
}
