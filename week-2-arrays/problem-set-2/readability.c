/*
NOTE: This version has a lot of my personal notes and logic behind my steps. I won't delete these for future reference. There's another file 'CS50/week-2-arrays/problem-set-2/readability_better_syntax.c" with better syntax that I created for submission purpose.
*/

/*
L is the average number of letters per 100 words in the text, and S is the average number of sentences per 100 words in the text.
*/

/*
Thought process:

1. Need to calculate L and S. Make these two functions?

1a:: function L
- find the number of letters in the text: how?
    - initialize a number for the number of letters (let's call it letterNum)
    - need a loop to go through all the input string elements
    - make sure to excude anything that isn't an alphabet (symbols, blankspaces, etc.) --> I think there's something like isNumber or something similar? --> if/else statement as well? then do letterNum += 1
    - divide letterNum by 100 and return it

1b:: function S
- find the number of sentences in the text: how?
    - initialize sentenceNum = 0 first
    - get a loop to go through all the input string elements
    - create an if/else statement (if ... || ... ||...) that can correctly identify a sentence... conditions below:
        - if there's a fullstop OR an exclamation mark OR a question mark (do the rest later after first completing the simpler version -----> OR ellipsis (...) OR quotation marks followed by a period
        (also have to skip:
            - Mr., Mrs., Dr., etc..
            - Numbers and URLS (3.14, https://global.rakuten.com, etc)
            )
        -

2. Make sure the functions are declared in float!
3. If/else comparison
    - do the rounding off only when printing the result (whether it's Below Grade 1, Grade 2, Grade 3, etc.)

4. To calculate word: HOW?
    - HAVE to determine how many words are there.
    - let's say a paragraph has 40 words, 184 letters, and 2 sentences.
    - 40 words - 184 letters - 2 sentences
    - 100 words - 184/40 * 100 letters - 2/40 * 100 sentences

*/

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

float functionL(string text);
float functionS(string text);
float functionW(string text);

int main(void){
    string text = get_string("Text: ");

    // just adding functionW(text) here for debugging
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
    // printf("%s\n%i\n", text, index);
    // printf("%i\n%i\n", L, S);
}

/*1a:: function L
- find the number of letters in the text: how?
    - initialize a number for the number of letters (let's call it letterNum)
    - need a loop to go through all the input string elements
    - make sure to excude anything that isn't an alphabet (symbols, blankspaces, etc.) --> I think there's something like isNumber or something similar? --> if/else statement as well? then do letterNum += 1
    - divide letterNum by 100 and return it
*/

// WE NEED TO CALCULATE WORD COUNT AS WELL.
float functionL(string text){
    int letterNum = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letterNum += 1;
        }
    }
    // printf("Number of letters: %i\n", letterNum);
    float letterL = (letterNum / functionW(text)) * 100;
    // printf("L value after the formula change: %f\n", letterL);
    return letterL;
}

    // - let's say a paragraph has 40 words, 184 letters, and 2 sentences.
    // - 40 words - 184 letters - 2 sentences
    // - 100 words - 184/40 * 100 letters - 2/40 * 100 sentences

/*
1b:: function S
- find the number of sentences in the text: how?
    - initialize sentenceNum = 0 first
    - get a loop to go through all the input string elements
    - create an if/else statement (if ... || ... ||...) that can correctly identify a sentence... conditions below:
        - if there's a fullstop OR an exclamation mark OR a question mark (do the rest later after first completing the simpler version -----> OR ellipsis (...) OR quotation marks followed by a period
        (also have to skip:
            - Mr., Mrs., Dr., etc..
            - Numbers and URLS (3.14, https://global.rakuten.com, etc)
            )
*/
float functionS(string text) {
    int sentenceNum = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentenceNum += 1;
        }
    }
    // printf("Number of sentences: %i\n", sentenceNum);
    float sentenceS = (sentenceNum / functionW(text)) * 100;
    // printf("S value after the formula change: %f\n", sentenceS);
    return sentenceS;
}

float functionW(string text) {
    // as we're calculating the number of whirtespaces, which is always 1 less than the total word count.
    int wordNum = 1;

    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            // printf("%c\n", text[i]);
            wordNum += 1;
        }
    }
    // printf("Number of words: %i\n", wordNum);
    return wordNum;
}
