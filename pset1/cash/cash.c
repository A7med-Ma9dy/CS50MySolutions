#include<stdio.h>
#include<cs50.h>
#include<math.h>
int main(void)
{
    //declare all variables
    int cents, count25, count10, count5, count1;
    //Get,check if negative and convert dollars to cents
    do
    {
        cents = round(get_float("change owned: ") * 100);
    }
    while (cents < 0);

    //count no. of cents
    count25 = cents / 25;
    count10 = (cents % 25) / 10;
    count5 = ((cents % 25) % 10) / 5;
    count1 = (((cents % 25) % 10) % 5) / 1;
    printf("%i\n", count25 + count10 + count5 + count1);

    //another solution

    int counter = 0;

    while (cents > 24)
    {
        cents = cents - 25;
        counter++;
    }
    while (cents > 9)
    {
        cents = cents - 10;
        counter++;
    }
    while (cents > 4)
    {
        cents = cents - 5;
        counter++;
    }

    counter = counter + cents;

    printf("%i\n", counter);
}