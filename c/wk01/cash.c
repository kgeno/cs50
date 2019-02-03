#include <stdio.h>
#include <math.h>
#include <cs50.h>

void change(float dollars);

int main(void)
{
    
    float dollars = get_float("Change owed: ");
    
    if (dollars < 0)
    {
        dollars = get_float("Change owed: ");
    }
        
    change(dollars);
}

void change(float dollars)
{
    int coins = round(dollars * 100);
    int arr[4] = {25, 10, 5, 1};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    int count = 0;
    
    for (int i = 0; i < arrSize; i++)
    {
        if (coins >= arr[i])
        {
            
            while (coins >= arr[i])
            {
                coins -= arr[i];
                count++;
            }
        }
    }
    
    printf("%d\n", count);
}