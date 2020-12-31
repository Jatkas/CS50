// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = LENGTH * 'z';

//total words variable
int words = 0;

// Hash table
node* table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int number = hash(word);
    
    node* cursor = table[number];
    
    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
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
    int number = 0;
    
    for (int i = 0; i < strlen(word); i++)
    {
        number += tolower(word[i]);
    }
    
    return (number % N);
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{

    FILE* file = fopen(dictionary, "r");

    if (file == NULL)
    {
        printf("Dictionary does not exist.\n");
        return false;
    }

    char word[LENGTH + 1];
    
    while (fscanf(file, "%s", word) != EOF)
    {
        node* new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            unload();
            return false;
        }
    
        strcpy(new_node->word, word);
        new_node->next = NULL;
        
        int number = hash(word);
        if(table[number] == NULL)
        {
            table[number] = new_node;
        }
        else
        {
            new_node->next = table[number];
            table[number] = new_node;
        }
        words++;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return words;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node* head = table[i];
        node* cursor = head;
        node* temp = head;
        
        while (cursor != NULL)
        {
            cursor = cursor->next;
            free(temp);
            temp = cursor;
        }
    }
    return true;
}
