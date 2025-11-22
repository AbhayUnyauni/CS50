#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int average;
    for(int h = 0; h < height; h++){
        for(int w = 0; w < width; w++){
            average = round((image[h][w].rgbtRed + image[h][w].rgbtBlue + image[h][w].rgbtGreen) / 3.0);
            image[h][w].rgbtRed = average;
            image[h][w].rgbtBlue = average;
            image[h][w].rgbtGreen = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp;
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width/2; j++){
            temp = image[i][j];
            image[i][j]= image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
     RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float tempRed = 0, tempGreen = 0, tempBlue = 0, pixelCount = 0;

            for(int local_i = i - 1; local_i <= i + 1; local_i++)
            {
                for(int local_j = j - 1; local_j <= j + 1; local_j++)
                {
                    if(local_i >= 0 && local_i < height && local_j >= 0 && local_j < width)
                    {
                        tempRed += image[local_i][local_j].rgbtRed;
                        tempGreen += image[local_i][local_j].rgbtGreen;
                        tempBlue += image[local_i][local_j].rgbtBlue;

                        pixelCount ++;
                    }
                }
            }
            temp[i][j].rgbtRed = round(tempRed / pixelCount);
            temp[i][j].rgbtGreen = round(tempGreen / pixelCount);
            temp[i][j].rgbtBlue = round(tempBlue / pixelCount);
        }
    }
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
