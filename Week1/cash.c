#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

int calculate_25(int change);
int calculate_10(int change);
int calculate_05(int change);
int calculate_01(int change);

int main(void)
{
    int change;
    // Prompt for geting the change owned value
    do
    {
        change = get_int("Change owed:");
    }
    while ((change < 0) || (isdigit(change)));

    // Remove as much 25 as possible from the start value
    int c25 = calculate_25(change);
    change = change - (c25 * 25);

    // Remove as much 10 as possible from the start value
    int c10 = calculate_10(change);
    change = change - (c10 * 10);

    // Remove as much 5 as possible from the start value
    int c05 = calculate_05(change);
    change = change - (c05 * 5);

    // Remove as much 1 as possible from the start value
    int c01 = calculate_01(change);
    change = change - c01;

    // Print the total of coins
    int total = c25 + c10 + c05 + c01;
    printf("%i\n", total);
}

// Calculate how many 25 to use
int calculate_25(int change)
{
    int count_25 = 0;
    while (change >= 25)
    {
        count_25++;
        change = change - 25;
    }
    return count_25;
}

// Calculate how many 10 to use
int calculate_10(int change)
{
    int count_10 = 0;
    while (change >= 10)
    {
        count_10++;
        change = change - 10;
    }
    return count_10;
}

// Calculate how many 05 to use
int calculate_05(int change)
{
    int count_05 = 0;
    while (change >= 5)
    {
        count_05++;
        change = change - 5;
    }
    return count_05;
}

// Calculate how many 01 to use
int calculate_01(int change)
{
    int count_01 = 0;
    while (change >= 1)
    {
        count_01++;
        change = change - 1;
    }
    return count_01;
}
