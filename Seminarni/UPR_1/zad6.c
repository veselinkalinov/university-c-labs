#include <stdio.h>

int main()
{
    int a, b, h;
    printf("Enter side a:");
    printf("\nEnter side b:");
    printf("\nEnter height h:");
    scanf("%d", &a, &b, &h);

    int s = ((a + b) * h) / 2;
    printf("%d = ", s);
    return 0;
}
