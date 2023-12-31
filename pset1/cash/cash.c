#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents(void)
{
    int centsf;
    do
    {
        centsf = get_int("Enter number of cents please:\n");
    }
    while (centsf < 0);
    return centsf;
}

int calculate_quarters(int centsf)
{
    // TODO
    // cents >= 25 >>> return one 25
    // cents >= 50 >>> return two 25's
    // cents >= 75 >>> return three 25's
    // well that seems a loop

    int q = 25;
    int noq = 0;
    while (centsf >= q)
    {
        noq++;
        q = q + 25;
    }
    return noq;
}

int calculate_dimes(int centsf)
{
    // Same as quarters but d is initialized with 10
    int d = 10;
    int nod = 0;
    while (centsf >= d)
    {
        nod++;
        d = d + 10;
    }
    return nod;
}

int calculate_nickels(int centsf)
{
    int n = 5;
    int non = 0;
    while (centsf >= n)
    {
        non++;
        n = n + 5;
    }
    return non;
}

int calculate_pennies(int centsf)
{
    int p = 1;
    int nop = 0;
    while (centsf >= p)
    {
        nop++;
        p = p + 1;
    }
    return nop;
}
