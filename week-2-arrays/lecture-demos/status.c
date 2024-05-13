#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Missing command-line argument\n");
        return 1; // this is arbitrary, just make sure it's not 0
    }

    printf("hello, %s\n", argv[1]);
    return 0; // means this is correct -- the code has "succeeded"
}
