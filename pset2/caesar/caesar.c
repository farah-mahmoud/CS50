#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
bool only_digits(string word);
char rotate(char text, int move);
int main(int argc, string argv[])
{
    //to check that the user will enter only one digit
    //notice that ./caesar is counted as 1 so it shouldn't be argc == 0
    if (argc == 1 || argc > 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    //making sure the user will not enter ANY non-digits like ./caesar 20x
    //by calling only_digits function
    for (int i = 1; i < argc; i++)
    {
        if (!only_digits(argv[i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    //converting string argv[] to userkey (aka: integer key)
    int key = atoi(argv[1]);

    //getting input from user
    string plaintext = get_string("plaintext:  ");
    printf("ciphertext: ");

    //rotating input by calling rotate function
    for (int i = 0; i < strlen(plaintext); i++)
    {
        printf("%c", rotate(plaintext[i], key));
    }
    printf("\n");
    return 0;
}
//function to make sure the user will pass only integer key
bool only_digits(string word)
{
    int length = strlen(word);
    for (int i = 0; i < length; i++)
    {
        if (isdigit(word[i]))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}
//function that rotates text
char rotate(char c, int k)
{
    if (isupper(c))
    {
        c = ((c - 65 + k) % 26 + 65);
    }
    else if (islower(c))
    {
        c = ((c - 97 + k) % 26 + 97);
    }
    else
    {
        return c;
    }
    return c;
}