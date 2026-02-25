#include <stdio.h>

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
    return 0;
}
