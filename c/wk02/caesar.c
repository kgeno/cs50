#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void caesar(string plain, int key);

int main(int argc, string argv[])
{
    // Check if argument is passed and if it's a number
    if (argc != 2 || atoi(argv[1]) == 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // Convert passed arg string to integer
    string a = argv[1];
    int key = atoi(a);
    
    string plain = get_string("plaintext: ");

    caesar(plain, key);
}

/************************
 * Caesar's Cipher
 ***********************/

void caesar(string plain, int key)
{
    for (int i = 0, n = strlen(plain); i < n; i++)
    {
        // Check if alphabetical character
        if (isalpha(plain[i]))
        {
            // Upper case
            if (isupper(plain[i]))
            {
                plain[i] = (plain[i] + key - 65) % 26 + 65;
            }
            // Lower case
            else
            {
                plain[i] = (plain[i] + key - 97) % 26 + 97;
            }
        }
    }
    
    printf("ciphertext: %s\n", plain);
}
