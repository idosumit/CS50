#include <cs50.h>
#include <stdio.h>

void print_row(int blank, int hash);

int main(void)
{
    // Prompt the user for the pyramid's height
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1);

    // Print a pyramid of that height
    for (int i = 0; i < height; i++)
    {
        // Print row of bricks
        print_row(height - i - 1, i + 1);
    }
}

void print_row(int blank, int hash)
{
    for (int a = blank; a > 0; a--)
    {
        printf(" ");
    }
    for (int b = 0; b < hash; b++)
    {
        printf("#");
    }
    printf("\n");
}
