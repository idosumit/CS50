#include <cs50.h>
#include <stdio.h>

// prompt the user for an amount greater than 0
// there are 4 amounts: 25, 10, 5, and 1.

// To do:
// implement a program in C that prints the minimum coins needed to make the
// given amount of change, in cents.

int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Prompt the user for change owed, in cents
    int cents, total_coins;

    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 0);

    int quarters = calculate_quarters(cents);
    cents = cents - (quarters * 25);

    int dimes = calculate_dimes(cents);
    cents = cents - (dimes * 10);

    int nickels = calculate_nickels(cents);
    cents = cents - (nickels * 5);

    int pennies = calculate_pennies(cents);
    cents = cents - pennies;

    total_coins = quarters + dimes + nickels + pennies;

    printf("%i\n", total_coins);
}

int calculate_quarters(int cents)
{
    int quarters = 0;
    while (cents >= 25)
    {
        quarters++;
        cents = cents - 25;
    }
    return quarters;
}

int calculate_dimes(int cents)
{
    int dimes = 0;
    while (cents >= 10 && cents < 25)
    {
        dimes++;
        cents = cents - 10;
    }
    return dimes;
}

int calculate_nickels(int cents)
{
    int nickels = 0;
    while (cents >= 5 && cents < 10)
    {
        nickels++;
        cents = cents - 5;
    }
    return nickels;
}

int calculate_pennies(int cents)
{
    int pennies = 0;
    while (cents > 0 && cents < 5)
    {
        pennies++;
        cents = cents - 1;
    }
    return pennies;
}
