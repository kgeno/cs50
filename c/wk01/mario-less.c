#include <cs50.h>
#include <stdio.h>

int main(void)
{    
    int num = get_int("Enter number betweer 1 and 8:\n");
    if (num < 1 || num > 8)
    {
        num = get_int("Enter number between 1 and 8:\n");
    }
                         
    for (int row = 0; row < num; row++)
    {
        for (int space = num - 1; space > row; space--)
        {
            printf(" ");
        }
        for (int block = 0; block <= row; block++) 
        {
            printf("#");    
        }
        printf("\n");
    }
}
