#include "helpers.h"
#include <math.h>
#include <stdio.h>
void swap(RGBTRIPLE *, RGBTRIPLE *);
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float grey;
            grey = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = grey;
            image[i][j].rgbtGreen = grey;
            image[i][j].rgbtBlue = grey;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float sepiaRed, sepiaGreen, sepiaBlue;
            //Calculating Sepia colors using Sepia Algorithm
            /*
            sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue
            sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue
            sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue*/
            sepiaRed = round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue);
            sepiaGreen = round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue);
            sepiaBlue = round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue);
            //Making sure rgb value 0 - 255
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            //Applying Sepia to the image pexils
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;

        }
    }
    return;
}

void swap(RGBTRIPLE *num1, RGBTRIPLE *num2)
{
    RGBTRIPLE temp;
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    /*swap(image[0][0], image[0][5])
    swap(image[0][1], image[0][4])
    swap(image[0][2], image[0][3])*/
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            swap(&image[i][j], &image[i][width - j - 1]);
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //make copy of the image, used for reading values
    RGBTRIPLE copy[height][width];

    for (int c = 0; c < height; c++)
    {
        for (int v = 0; v < width; v++)
        {
            copy[c][v] = image[c][v];
        }
    }

    //nest loop
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //initiate buffers, dividend
            int sumRed, sumGreen, sumBlue;
            sumRed = sumGreen = sumBlue = 0;
            float avg = 0;

            //loop through surrounding pixels
            for (int k = i - 1; k <= (i + 1); k++)
            {
                for (int l = j - 1; l <= (j + 1); l++)
                {
                    if (k >= 0 && k < height && l >= 0 && l < width)
                    {
                        sumRed += copy[k][l].rgbtRed;
                        sumGreen += copy[k][l].rgbtGreen;
                        sumBlue += copy[k][l].rgbtBlue;

                        avg++;
                    }
                }
            }

            //apply blur values; reset parameters
            image[i][j].rgbtRed = round(sumRed / avg);
            image[i][j].rgbtGreen = round(sumGreen / avg);
            image[i][j].rgbtBlue = round(sumBlue / avg);
        }
    }
    return;
}
