#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void vingenere(string plain, string keyword);

int main(int argc, string argv[])
{
    if (argc != 2 || atoi(argv[1]) != 0)
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }

    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (atoi(&argv[1][i]) != 0)
        {
            printf("Usage: ./vigenere keyword\n");
            return 1;
        }
    }

    string keyword = argv[1];

    string plain = get_string("plaintext: ");

    vingenere(plain, keyword);
}

void vingenere(string plain, string keyword)
{
    int kwLen = strlen(keyword);
    for (int i = 0, p = strlen(plain), k = 0; i < p; i++, k++)
    {
        // Go to beginning of keyword if shorter than plain
        if (k >= kwLen)
        {
            k = 0;
        }
        // If plain[i] is not alphabetical - skip key / take a step back
        if (!isalpha(plain[i]))
        {
            k--;
        }
        // If key is alphabetical - find key position from 0 to 26 (A-Z)
        char key = (isupper(keyword[k])) ? keyword[k] - 65 : keyword[k] - 97;

        // Check if alphabetical character
        if (isalpha(plain[i]))
        {
            // Shift upper case
            if (isupper(plain[i]))
            {
                plain[i] = (plain[i] + key - 65) % 26 + 65;
            }
            // Shift lower case
            else
            {
                plain[i] = (plain[i] + key - 97) % 26 + 97;
            }
        }
    }

    printf("ciphertext: %s\n", plain);
}