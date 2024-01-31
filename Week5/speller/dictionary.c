// Implements a dictionary's functionality

#include "dictionary.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Variables
unsigned int word_count;
unsigned int hash_value;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    // Hash the word to obtain a hash value
    hash_value = hash(word);

    // Point cursor to the first node
    node *cursor = table[hash_value];

    // Go through the linked list
    while (cursor != 0)
    {
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned long total = 0;
    for (int i = 0; i < strlen(word); i++)
    {

        total += tolower(word[i]);
    }
    return total % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open the dictionary file
    FILE *source = fopen(dictionary, "r");

    if (source == NULL)
    {
        printf("Cannot open %s\n", dictionary);
        return false;
    }
    // Read each word in the file until EOF
    char word[LENGTH + 1];

    while (fscanf(source, "%s", word) != EOF)
    {
        // Allocate memory for a new node
        node *n = malloc(sizeof(node));

        if (n == NULL)
        {
            return false;
        }
        // Copy word to node
        strcpy(n->word, word);
        // Add each word to the hash table
        hash_value = hash(word);
        // Set the pointer of the new node to the current head of the table
        n->next = table[hash_value];
        // Set the new node to the head of the list
        table[hash_value] = n;
        word_count++;
    }

    // Close the dictionary file
    fclose(source);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // Return size of dictionary
    if (word_count > 0)
    {
        return word_count;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // Iterate through all the buckets
    for (int i = 0; i < N; i++)
    {
        // Point cursor to start of the linked list
        node *cursor = table[i];

        // If cursor is not NULL, free memory
        while (cursor != NULL)
        {
            // Create tmp to not lose access to rest of the list while freeing the memory
            node *tmp = cursor;
            // Point cursor to the next node
            cursor = cursor->next;
            // Free temp for each node
            free(tmp);
        }
    }
    return true;
}
