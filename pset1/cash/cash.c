#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void) {
    // get the amount of cash from the user, checking for positive
    float dollars;
    do
    {
        dollars = get_float("Change owed: ");
    }
    while (dollars < 0);

    // convert to int to avoid imprecision errors
    int cents = round(dollars * 100);

    // use a greedy approach to get the minimum number of coins
    int minCoins = 0;
    while (cents > 0) {
        if (cents >= 25) {
            minCoins++;
            cents -= 25;
        }
        else if (cents >= 10)
        {
            minCoins++;
            cents -=10;
        }
        else if (cents >= 5)
        {
            minCoins++;
            cents -=5;
        }
        else
        {
            minCoins++;
            cents--;
        }
    }

    printf("%i\n", minCoins);
}



