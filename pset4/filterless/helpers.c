#include "helpers.h"
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float average = round(((float)image[i][j].rgbtRed + (float)image[i][j].rgbtGreen + (float)image[i][j].rgbtBlue) / 3.00);
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
    return;
}
//limit function to 255 color number
int limit(int rgb)
{
    if (rgb > 255)
    {
        rgb = 255;
    }
    return rgb;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sepiaRed = limit(round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue));
            int sepiaGreen = limit(round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue));
            int sepiaBlue = limit(round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue));
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (width / 2); j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //make an image to put the copy of this image until we substitute after we finish
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (width); j++)
        {
            float sumred, sumgreen, sumblue, counter;
            sumred = sumgreen = sumblue = counter = 0.00;
            //iterate over box surrounding pixel or what is left of it if pixel in the corner or edge
            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    int cux = i + x;
                    int cuy = j + y;
                    //check edges of image
                    if (cux < 0 || cux > (height - 1) || cuy < 0 || cuy > (width - 1))
                    {
                        continue;
                    }
                    //get sum of each color from surrounding pixels and the one in question
                    sumred += image[cux][cuy].rgbtRed;
                    sumgreen += image[cux][cuy].rgbtGreen;
                    sumblue += image[cux][cuy].rgbtBlue;
                    counter++;
                }
                //calculate average of each color of surrounding + 1 pixels to get this pixel color 
                temp[i][j].rgbtRed = round(sumred / counter);
                temp[i][j].rgbtGreen = round(sumgreen / counter);
                temp[i][j].rgbtBlue = round(sumblue / counter);
            }
        }
    }
    //copy temp image to original one
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
    return;
}
