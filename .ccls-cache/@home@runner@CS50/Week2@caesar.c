#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char LOWER[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

char UPPER[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

string cipher(string plaintext , int key);

int main (int argc, string argv[])
{
    //Check for 2 arguments
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    //Check for non-numeric keys
    for (int i = 0, len = strlen(argv[1]); i < len; i++)
    {
        if(!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    //Get the input from the command-line and convert the string to int
    int key = atoi(argv[1]);

    //Prompt for plaintext
    string plaintext = get_string("plaintext: ");

    //Encrypts the input
    string ciphertext = cipher(plaintext, key);

    //Prints the Encripted message
    printf("ciphertext: %s\n", ciphertext);
}

string cipher(string plaintext, int key)
{
    string ciphertext = plaintext;

    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        if(!isalpha(plaintext[i]))
        {
            ciphertext[i] = plaintext[i];
        }
        else
        {
            for (int j = 0; j < 26; j++)
            {

                    if (plaintext[i] == LOWER[j])
                    {
                        ciphertext[i] = LOWER[(j + key) % 26];
                        i++;
                    }
                    else if (plaintext[i] == UPPER[j])
                    {
                        ciphertext[i] = UPPER[(j + key) % 26];
                        i++;
                    }

            }
            i--;
        }
    }

    return ciphertext;
}
