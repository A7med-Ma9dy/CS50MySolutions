#include <cs50.h>
#include <stdio.h>
void makeSpace(int space);
void makeHash(int hash);
void middleSpace();
void newline();
int main(void)
{
    //prompt user for integar input bet 1&8
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    //iterate to form pyramid starting from row 1 not zero
    for (int hash = 1; hash <= height; hash++)
    {
        makeSpace(height - hash);
        makeHash(hash);
        middleSpace();
        makeHash(hash);
        newline();
    }

}
//make space first
void makeSpace(int space)
{
    for (int j = 1; j <= space; j++)
    {
        printf(" ");
    }
}
//make hashes
void makeHash(int hash)
{
    for (int z = 1; z <= hash; z++)
    {
        printf("#");
    }
}
// just space between sides
void middleSpace()
{
    printf("  ");
}
//new line after each row
void newline()
{
    printf("\n");
}