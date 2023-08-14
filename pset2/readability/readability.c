#include <cs50.h>
#include <stdio.h>
#include <ctype.h> //to use the isalpha function to make sure the user inputs alphates only(uppercase or lowercase)
#include <string.h> //to use strlen function to know size of string
#include <math.h>
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string usertext = get_string("Enter your text: ");
    // assign these three variables to float to avoid integer division
    float no_letters = count_letters(usertext);
    float no_words = count_words(usertext);
    float no_sentences = count_sentences(usertext);
    //printf("Text: %s\n", usertext);
    //printf("Number of letters: %i\n", count_letters(usertext));
    //printf("Number of words: %i\n", count_words(usertext));
    //printf("Number of sentences: %i\n", count_sentences(usertext));
    float avg_L = ((no_letters / no_words) * 100);
    float avg_S = ((no_sentences / no_words) * 100);
    //printf("avg_L: %f\n", avg_L);
    //printf("avg_S: %f\n", avg_S);
    //printf("%d\n", 10/2);
    float index = 0.0588 * avg_L - 0.296 * avg_S - 15.8;
    float grade = round(index);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %.f\n", grade);
    }
}

int count_letters(string text)
{
    int lettersnumber = strlen(text);
    int L = 0;
    for (int i = 0; i < lettersnumber; i++)
    {
        if (isalpha(text[i]))
        {
            L++;
        }
    }
    return L;
}

int count_words(string text)
{
    int W = 0;
    int lettersnumber = strlen(text);
    for (int i = 0; i < lettersnumber; i++)
    {
        if (isspace(text[i]))
        {
            W++;
        }
    }
    return (W + 1);
}

int count_sentences(string text)
{
    int S = 0;
    int lettersnumber = strlen(text);
    for (int i = 0; i < lettersnumber; i++)
    {
        if (text[i] == '!' || text[i] == '.' || text[i] == '?')
        {
            S++;
        }
    }
    return S;
}