#include <cs50.h>
#include <stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
int main(void)
{
    int letters = 0;
    int words = 1; //Hello word is 2 words not one
    int sentences = 0;

    string text = get_string("Text: ");

    //count the number of letters, words, and sentences in the text.

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        //if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        char ch = text[i];
        if (isalpha(ch))
        {
            letters++;
        }
        //else if (text[i] == ' ')
        else if (isspace(ch))
        {
            words++;
        }
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }

    //the Coleman-Liau index is computed using the formula
    float index = 0.0588 * (letters / (float) words) * 100 - 0.296 * (sentences / (float) words) * 100 - 15.8;
    if (index > 0 && index < 16)
    {
        printf("Grade %i\n", (int) round(index));
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Before Grade 1\n");
    }
    return 0;
}