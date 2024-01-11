#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Read text input
    string text = get_string("Text: ");

    int letters = 0;
    int words = 1;
    int sentences = 0;

    // Count the number of letters, words, and sentences in the text
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
        if ((text[i] == '.') || (text[i] == '!') || (text[i] == '?'))
        {
            sentences++;
        }
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    // L is the average number of letters per 100 words in the text
    float L = ((float) letters / (float) words) * 100;

    // S is the average number of sentences per 100 words in the text.
    float S = ((float) sentences / (float) words) * 100;

    // Calculate Coleman-Liau index
    double index = 0.0588 * L - 0.296 * S - 15.8;

    // For testing the values
    /*
    printf("letters: %i\n", letters);
    printf("words: %i\n", words);
    printf("sentences: %i\n", sentences);
    printf("L: %f\n", L);
    printf("S: %f\n", S);
    */

    // Print the Grade
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %.0f\n", round(index));
    }
}
