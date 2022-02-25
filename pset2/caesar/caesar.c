#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        string num = argv[1];
        int key = atoi(num);
        string plaintext = get_string("plaintext: ");
        printf("ciphertext: ");
        for (int i = 0, len = strlen(plaintext); i < len; i++)
        {
            if (isalpha(plaintext[i]))
            {
                if (islower(plaintext[i]))
                {
                    printf("%c", ((((plaintext[i] - 97) + key) % 26) + 97));
                }
                else if (isupper(plaintext[i]))
                {
                    printf("%c", ((((plaintext[i] - 65) + key) % 26) + 65));
                }
            }
            else
            {
                printf("%c", plaintext[i]);
            }
        }
        printf("\n");
        return 0;
    }
    else
    {
        printf("error");
        return 1;
    }
}