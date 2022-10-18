#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    int n = atoi(argv[1]);
    string rotate = get_string("plaintext: ");
    printf("ciphertext: ");
    for (int j = 0; j < strlen(rotate); j++)
    {
        if (isupper(rotate[j]))
        {
            printf("%c", (rotate[j] - 65 + n) % 26 + 65);
        }
        else if(islower(rotate[j]))
        {
            printf("%c", (rotate[j] - 97 + n) % 26 + 97);
        }
        else
        {
            printf("%c", rotate[j]);
        }
    }
    printf("\n");
}