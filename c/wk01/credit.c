/* Luhn's Algorithm for validating credit cards
 * ============================================
 * 1. Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
 * 2. Add the sum to the sum of the digits that weren’t multiplied by 2.
 * 3. If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!
 */

#include <stdio.h>
#include <cs50.h>

void validate(long long number);

int main(void)
{
    long long number = get_long("Number: ");
    validate(number);
}
// Validate Credit Card
void validate(long long number)
{
    int *n = malloc(sizeof(number));
    // Keep array size since it's dynamically allocated
    int arrSize = 0;
    long long prev = number;
    int sum = 0;
    
    // Push CC digits into an array last to first using modulus
    for (int i = 0; i < prev * 10; i++)
    {
        number = prev / 10;
        n[i] = prev % 10;
        prev = number;
        arrSize++;
        // Check if array index is even or odd to use values for Luhn's algorithm
        // Add digits not multiplied by 2
        if (i % 2 == 0)
        {
            sum += n[i];
        }
        // Add digigs multiplied by 2
        else
        {
            int multiply = n[i] * 2;
            // If product is more than two digits - add those together
            if (multiply > 9)
            {
                int mSum = 0, remainder;
                
                while (multiply != 0)
                {
                    remainder = multiply % 10;
                    mSum += remainder;
                    multiply /= 10;
                }
                
                sum += mSum;
            }
            else
            {
                sum += multiply;
            }
        }
    }
    // If totals last digit is 0 and the number of digets is 13 or more the card is valid
    if (sum % 10 == 0 && arrSize > 12 && arrSize < 17)
    {
        // Check for CC Issuer
        switch (n[arrSize - 1])
        {
            case 3:
                if (n[arrSize - 2] == 4 || n[arrSize - 2] == 7)
                {
                    printf("AMEX\n");
                }
                else
                {
                    printf("INVALID\n");
                }
                break;
            case 4:
                printf("VISA\n");
                break;
            case 5:
                if (n[arrSize - 2] > 0 && n[arrSize - 2] < 6)
                {
                    printf("MASTERCARD\n");
                }
                else
                {
                    printf("INVALID\n");
                }
                break;
            default:
                printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}