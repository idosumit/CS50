/*
logic

- needs to take in 2 inputs from the user
- need to create something (array?) to store the scores corresponding to the letters (either capital
or small, related to the point below)
- capital or small --> same thing --> so, need to convert one to other before applying points
- probably will need to create a function to get total points, and those total points need to be
stored in the 2 variables
- create 2 variables to get the total points of player 1 and player 2 each
- draw comparison and print out the winner, or print out the tie
*/

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int score_calculation(string wordx);

int main(void)
{
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");
    int score1 = score_calculation(word1);
    int score2 = score_calculation(word2);

    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
        printf("Tie!\n");
}

int score_calculation(string wordx)
{
    int score = 0;
    for (int i = 0; i < strlen(wordx); i++)
    {
        if (isupper(wordx[i]))
        {
            score += POINTS[wordx[i] - 'A'];
        }
        else if (islower(wordx[i]))
        {
            score += POINTS[wordx[i] - 'a'];
        }
    }
    return score;
}