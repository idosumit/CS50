#include <cs50.h>
#include <stdio.h>

// prompt the user for an amount greater than 0
// there are 4 amounts: 25, 10, 5, and 1.

// To do:
// implement a program in C that prints the minimum coins needed to make the
// given amount of change, in cents.

int calculate_total_coins(int cents);

int main(void)
{
    int cents;

    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 0);

    int total_coins = calculate_total_coins(cents);
    printf("%i\n", total_coins);
}

int calculate_total_coins(int cents)
{
    int total_coins = 0, quarters = 0, dimes = 0, nickels = 0, pennies = 0;

    while (cents >= 25)
    {
        quarters++;
        cents = cents - 25;
    }

    while (cents >= 10 && cents < 25)
    {
        dimes++;
        cents = cents - 10;
    }

    while (cents >= 5 && cents < 10)
    {
        nickels++;
        cents = cents - 5;
    }

    while (cents >= 1 && cents < 5)
    {
        pennies++;
        cents = cents - 1;
    }

    total_coins = quarters + dimes + nickels + pennies;
    return total_coins;
}
