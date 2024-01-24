#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // Open the memory card
    FILE *card = fopen(argv[1], "r");

    // Check if the memory card is valid
    if (card == NULL)
    {
        printf("Could not open the file!\n");
        return 2;
    }

    // Create a buffer for a block of data (usigned char buffer[512];)
    unsigned char buffer[512];

    // Create a Counter for the number of JPEG files readed
    int counter = 0;

    // Pointer to output data
    FILE *img = NULL;

    // Allocate memory for filename
    char *filename = malloc(8 * sizeof(char));

    // While there's still data left to read from the memory card
    while (fread(buffer, 1, 512, card) == 512)
    {

        // If start of new JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            sprintf(filename, "%03i.jpg", counter);
            img = fopen(filename, "w");
            counter++;
        }
        if (img != NULL)
        {
            fwrite(buffer, 1, 512, img);
        }
    }
    // Close files
    free(filename);
    fclose(img);
    fclose(card);

    return 0;
}
