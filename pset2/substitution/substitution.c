#include <cs50.h> // to get plain text
#include <stdio.h>
#include <string.h>// for strlen()
#include <ctype.h>// for string operation upper, lower

void substitution(string key, string plaintext);
void alpha_converter(string key, char pi);
int main(int argc, string argv[])
{
    //validate key
    if (argc == 2)
    {
        int len = strlen(argv[1]);
        if (len == 26)
        {
            for (int i = 0; i < len; i++)
            {
                if (! isalpha(argv[1][i]))
                {
                    printf("key must contain alpha characters.\n");
                    return 1;
                }
                for (int j = i + 1; j < len; j++)
                {
                    if (toupper(argv[1][j]) == toupper(argv[1][i]))
                    {
                        printf("key must not contain repeated characters.\n");
                        return 1;
                    }
                }
            }
            string plaintext = get_string("plaintext: ");
            substitution(argv[1], plaintext);
        }
        else
        {
            printf("Key must contain 26 characters\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    return 0;
}

void substitution(string key, string plaintext)
{
    printf("ciphertext: ");
    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        if (isalpha(plaintext[i]))
        {
            alpha_converter(key, plaintext[i]);
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}

void alpha_converter(string key, char pi)
{
    string alpha = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0, len = strlen(alpha); i < len; i++)
    {
        if (tolower(pi) == alpha[i])
        {
            if (islower(pi))
            {
                printf("%c", tolower(key[i]));
            }
            else
            {
                printf("%c", toupper(key[i]));
            }
        }
    }
}