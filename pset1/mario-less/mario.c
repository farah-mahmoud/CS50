#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    //getting height input from user

    do
    {
        height = get_int("Enter height of the pyramid: \n");
    }
    //checking if height is between 1 & 8

    while (height < 1 || height > 8);

    //building the pyramid
    for (int i = 0; i < height; i++)
    {
        for (int k = i; k < height - 1 ; k++)
        {
            printf(" ");
        }

        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }

        printf("\n");
    }

}