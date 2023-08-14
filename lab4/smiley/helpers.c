#include "helpers.h"
void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    //Loop for height
    for (int i = 0; i < height; i++)
    {
        //nested loop for width
        for (int j = 0; j < width; j++)
        {
            //Change the color to Blue
            image[i][j].rgbtBlue = 0xFF;
        }
    }
}
