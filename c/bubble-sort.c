#include <stdio.h>

void bubbleSort(int *arr, int arrSize);

int main(void)
{
    int arr[6];
    int arrSize = 0;
    
    for (int i = 0; i < 6; i++)
    {
        printf("Enter number %i: ", i + 1);
        scanf("%i", &arr[i]);
        arrSize++;
    }

    printf("Unsorted array: ");
    for (int i = 0; i < arrSize; i++)
    {
        printf("%i ", arr[i]);
    }

    bubbleSort(arr, arrSize);
}

/* Bubble Sort function
 * ====================
 * 1. Set swap counter to a non-zero value
 * 2. Repeat until swap counter is zero
 *    a. Reset swap counter
 *    b. Look at each adjacent pair
 *       - If elements are not in order - swap them, add 1 to the counter
 */
void bubbleSort(int *arr, int arrSize)
{
    // Set swap counter
    int swap = 1;
    // Set bubble to track index of last unsorted element
    int bubble = arrSize;
    // Copy array
    int sorted[arrSize];
    for (int i = 0; i < arrSize; i++)
    {
        sorted[i] = arr[i];
    }
    
    while (swap != 0 && bubble != 0)
    {
        // Reset swap counter
        swap = 0;
        // Iterate through each element
        for (int i = 0, j = 1; i < bubble; i++, j++)
        {
            int temp = sorted[i];
            // Compare adjacent pairs and swap if not in order
            if (sorted[i] > sorted[j] && i < arrSize - 1)
            {
                sorted[i] = sorted[j];
                sorted[j] = temp;

                swap++;
            }
        }
        // Cut off highest sorted value
        if(bubble != 0)
        {
            bubble--;
        }
    }
    // Print out sorted array
    printf("\nSorted array: ");


    for (int i = 0; i < arrSize; i++)
    {
        if (i == arrSize - 1)
        {
            printf("%i\n", sorted[i]);
        }
        else
        {
            printf("%i ", sorted[i]);
        }
    }
}