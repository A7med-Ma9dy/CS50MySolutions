// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>
#include <string.h>
#include<strings.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 100000;

// Hash table
node *table[N];

//dictionary size
int dictsize = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    /*
    int n = strlen(word);
    char copy[LENGTH + 1];
    for (int i = 0; i < n; i++)
    {
        copy[i] = tolower(word[i]);
    }
    copy[n] = '\0';
    */
    //hash word to obtain hash value
    int hashindex = hash(word);
    //access linked list at that index in hashtable
    node *cursor = table[hashindex];
    //Traverse linked list searching for word
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
    //add ASCII values of each character in word together
    int sum = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        sum += tolower(word[i]);
    }
    return sum % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // open dictionary file
    FILE *open = fopen(dictionary, "r");
    //check if null
    if (open == NULL)
    {
        fprintf(stderr, "Usage: Could not open %s.\n", dictionary);
        return false;
    }
    //initiallize buffer for word array
    char w[LENGTH + 1];
    //read strings from file one at a time
    while (fscanf(open, "%s", w) != EOF)
    {
        //allocate memory for new node for each word
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }
        //copy word into node
        strcpy(n->word, w);
        //obtain index in hash table {hash word}
        int hashindex = hash(w);
        //Insert node into hash table at that index
        n->next = table[hashindex];
        table[hashindex] = n;
        dictsize++;
    }
    //close file
    fclose(open);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return dictsize;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
        if (cursor == NULL && i == N - 1)
        {
            return true;
        }
    }
    return false;
}
