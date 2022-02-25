#include<stdio.h>
#include<cs50.h>

int main(void)
{
    long credit, creditCopy;
    int totalSum = 0, index = 0, length = 0;
    do
    {
        credit = get_long("Number: ");
        creditCopy = credit;
    }
    while (credit < 1);


    //make checksum, luhn's algorithm
    while (credit != 0)
    {
        if (index % 2 != 0)
        {
            int temp = 2 * (credit % 10);
            if (temp > 9)
            {
                totalSum += temp % 10 + temp / 10;
            }
            else
            {
                totalSum += temp;
            }
        }
        else
        {
            totalSum += credit % 10;
        }
        credit = credit / 10;
        index++;
    }

    if (totalSum % 10 == 0)
    {
        //Amex       uses 15-digit numbers,             start with 34 or 37
        //MasterCard uses 16-digit numbers,             start with 51, 52, 53, 54, or 55
        //Visa       uses 13- and 16-digit numbers,     start with 4
        int amex = creditCopy / 1e13;
        int mastercard = creditCopy / 1e14;
        int visa = creditCopy / 1e12;
        int visa2 = creditCopy / 1e15;
        if (index == 15 && (amex == 34 || amex == 37))
        {
            printf("AMEX\n");
        }
        else if (index == 16 && mastercard >= 51 && mastercard <= 55)
        {
            printf("MASTERCARD\n");
        }
        else if ((index == 13 || index == 16) && (visa == 4 || visa2 == 4))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}