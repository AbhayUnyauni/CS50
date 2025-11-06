#include "helpers.h"
#include <math.h>

// Convert image to grayscale
#define RED 0
#define GREEN 1
#define BLUE 2

int getBlur(int i, int j, int height, int width, RGBTRIPLE image[height][width], int color_position);

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

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaRed, sepiaBlue, sepiaGreen;

    // for sepiaRed
    for(int h = 0; h < height; h++){
        for(int w = 0; w < width; w++){

            sepiaRed = round(0.393 * image[h][w].rgbtRed + 0.769 * image[h][w].rgbtGreen + 0.189 * image[h][w].rgbtBlue);
            sepiaBlue = round(0.272 * image[h][w].rgbtRed + 0.534 * image[h][w].rgbtGreen + 0.131 * image[h][w].rgbtBlue);
            sepiaGreen = round(0.349 * image[h][w].rgbtRed + 0.686 * image[h][w].rgbtGreen + 0.168 * image[h][w].rgbtBlue);

            if(sepiaRed > 255){
                sepiaRed = 255;
            }
            if(sepiaBlue > 255){
                sepiaBlue = 255;
            }
            if(sepiaGreen > 255){
                sepiaGreen = 255;
            }

            image[h][w].rgbtRed = sepiaRed;
            image[h][w].rgbtBlue = sepiaBlue;
            image[h][w].rgbtGreen = sepiaGreen;
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

// Get Blur

int getBlur(int i, int j, int height, int width, RGBTRIPLE image[height][width], int color_position){
    float count = 0;
    int sum = 0;

    for(int row = (i-1); row <= (i + 1); row++){
        for(int column = (j - 1); column <= (j + 1); column++){
            if(row < 0 || row >= height || column < 0 || column >= width){
                continue;
            }
            if(color_position == RED){
                sum += image[row][column].rgbtRed;
            }else if(color_position == GREEN){
                sum += image[row][column].rgbtGreen;
            }else{
                sum += image[row][column].rgbtBlue;
            }
            count++;
        }
    }
    return round(sum / count);
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for(int i = 0; i < height; i++){
        for(int j = 0; j < height; j++){
            temp[i][j] = image[i][j];
        }
    }

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            image[i][j].rgbtRed = getBlur(i, j, height, width, temp, RED);
            image[i][j].rgbtGreen = getBlur(i, j, height, width, temp, GREEN);
            image[i][j].rgbtBlue = getBlur(i, j, height, width, temp, BLUE);
        }
    }
    return;
}
