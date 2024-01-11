#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Dictionaries for the points
char LOWER[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

char UPPER[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int DICTIONARY[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int calculate_points(string word);
int main(void)
{
    // Read the Players input
    string player1 = get_string("Player1: ");
    string player2 = get_string("Player2: ");

    // calculate both scores
    int score1 = calculate_points(player1);
    int score2 = calculate_points(player2);

    // Compare the scores and Print Result
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}
// Calculate Points
int calculate_points(string word)
{
    int score = 0;

    for (int i = 0, len = strlen(word); i < len; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if ((word[i] == LOWER[j]) || (word[i] == UPPER[j]))
            {
                score += DICTIONARY[j];
            }
        }
    }
    return score;
}
