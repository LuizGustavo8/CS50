#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int line = 0;
    int diff = 0;
    int Height;
    // Prompt user for positive integer
    do
    {
        Height = get_int("Height:");
    }
    while (Height < 1);

    // Print the lines until it gets to the Height
    while (line < Height)
    {
        // Keeps the value of the current line and the current diference between Height and line
        line++;
        diff = Height - line;

        // Print line by line
        for (int i = 0; i < line; i++)
        {
            // print spaces until it match the diference
            for (int j = 0; j < diff; j++)
            {
                printf(" ");
            }
            // resets the diference so it doesnt interfire in the next line and then prints the symbol
            diff = 0;
            printf("#");
        }
        // Jumps for the next line
        printf("\n");
    }
}
