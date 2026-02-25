#include <stdio.h>
#include <math.h>

// zad 1
int main()
{
    char ch;
    int width = 10, height = 5;

    printf("Enter symbol: ");
    scanf(" %c", &ch);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
                printf("%c", ch);
            else
                printf(" ");
        }
        printf("\n");
    }
}

// zad 2
int main()
{
    float inch;
    printf("Inches:");
    scanf("%f", &inch);
}
