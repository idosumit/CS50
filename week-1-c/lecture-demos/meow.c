#include <stdio.h>
#include <cs50.h>

void meow(int n);

int main(void)
{
    int n = get_int("Number of meows: ");
    meow(n);
}

void meow(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("meow\n");
    }
}
