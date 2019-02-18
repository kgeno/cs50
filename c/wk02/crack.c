#include <cs50.h>
#include <stdio.h>
#include <crypt.h>
#include <string.h>

int crack(string hash, string salt);

int main(int argc, string argv[])
{
    if (argc != 2 || strlen(argv[1]) != 13)
    {
        printf("Usage: ./crack hash\n");
        return 1;
    }
    
    char hash[13], salt[13];
    strcpy(hash, argv[1]);
    strncpy(salt, hash, 2);

    crack(hash, salt);
}

int crack(string hash, string salt)
{
    int abcLen = 53;
    char abc[53] = "\0abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char key[6] = "\0\0\0\0\0\0";
    
    for (int e = 0; e < abcLen; e++)
    {
        for (int d = 0; d < abcLen; d++)
        {
            for (int c = 0; c < abcLen; c++)
            {
                for (int b = 0; b < abcLen; b++)
                {
                    for (int a = 0; a < abcLen; a++)
                    {
                        key[0] = abc[a];
                        key[1] = abc[b];
                        key[2] = abc[c];
                        key[3] = abc[d];
                        key[4] = abc[e];
                        if (strcmp(crypt(key, salt), hash) == 0)
                        {
                            printf("%s\n", key);
                            return 0;
                        }
                    }
                }
            }
        }
    }
    return 2;
}