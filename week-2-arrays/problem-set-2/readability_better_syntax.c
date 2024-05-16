#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

float functionL(string text);
float functionS(string text);
float functionW(string text);

int main(void)
{
    string text = get_string("Text: ");

    int gradeLevel = round(0.0588 * functionL(text) - 0.296 * functionS(text) - 15.8);

    if (gradeLevel < 1)
    {
        printf("Before Grade 1\n");
    }
    if (gradeLevel >= 1 && gradeLevel <= 16)
    {
        printf("Grade %i\n", gradeLevel);
    }
    if (gradeLevel > 16)
    {
        printf("Grade 16+\n");
    }
}

float functionL(string text)
{
    int letterNum = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letterNum += 1;
        }
    }
    float letterL = (letterNum / functionW(text)) * 100;
    return letterL;
}

float functionS(string text)
{
    int sentenceNum = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentenceNum += 1;
        }
    }
    float sentenceS = (sentenceNum / functionW(text)) * 100;
    return sentenceS;
}

float functionW(string text)
{
    int wordNum = 1;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            wordNum += 1;
        }
    }
    return wordNum;
}
