#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height = get_int("Height: ");
    if (height < 1 || height > 8)
    {
        height = get_int("Height: ");
    }
    
    for (int row = 0; row < height; row++)
    {
        for (int space = height - 1; space > row; space--)
        {
            printf(" ");
        }
        
        for (int block = 0; block <= row; block++)
        {
            printf("#");
        }
        
        printf("  ");
        
        for (int block = 0; block <= row; block++)
        {
            printf("#");
        }
        
        printf("\n");
    }
}