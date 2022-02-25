#include <stdio.h>
#include <stdlib.h>
#include<stdint.h>

#define blocksize 512
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    //check input
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }
    //open input file and check if it can be opened
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        fprintf(stderr, "usage: couldn't open %s.\n", argv[1]);
        return 1;
    }

    BYTE buffer[blocksize];
    int imgcount = 0;
    char filename[8];
    //char *filename = malloc(8 * sizeof(char));
    FILE *output = NULL;

    //Read 512 bytes from input and store on the buffer
    while (fread(buffer, sizeof(BYTE), blocksize, input))
    {
        //checks first 4 bytes start with jpg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            /* if (imgcount != 0)
            {
                fclose(output);
            }
            */
            //write jpeg into file name in form 001.jpg, 002.jpg and so on
            sprintf(filename, "%03i.jpg", imgcount);
            //open Out_file for writing
            output = fopen(filename, "w");
            //image count for name
            imgcount++;
        }
        //Check if output have been used for valid input
        if (output != NULL)
        {
            fwrite(buffer, sizeof(BYTE), blocksize, output);
        }
    }
    //free(filename);
    fclose(input);
    fclose(output);
    return 0;
}