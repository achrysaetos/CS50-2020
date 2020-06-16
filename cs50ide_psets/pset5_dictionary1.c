#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <strings.h>
#include <stdio.h>

#include "dictionary.h"

typedef struct node{
    char word[LENGTH];
    struct node *next;
}
node;

const unsigned int N = 26;
node *table[N];
int totalWords = 0;

bool check(const char *word){ // returns true if word is in dictionary
    node *cursor = table[hash(word)];
    if (strcasecmp(cursor->word, word) == 0){ // compare words if case insensitive
        return true;
    }
    while (cursor->next != NULL){ // traverse through linked list
        cursor = cursor->next;
        if (strcasecmp(cursor->word, word) == 0){
            return true;
        }
    }
    return false;
}

unsigned int hash(const char *word){ // hashes word to number
    int n = (int) tolower(word[0]) - 97;
    return n;
}

bool load(const char *dictionary){ // loads dictionary into memory
    FILE *file = fopen(dictionary, "r");
    char *dictWord = malloc(LENGTH);
    if (dictWord == NULL){ // opens dictionary and creates space
        return false;
    }
    while (fscanf(file, "%s", dictWord) != EOF){ // reads file
        node *n = malloc(sizeof(node));// allocates memory in a node to store the word
        if (n == NULL){
            return false;
        }
        strcpy(n->word, dictWord);// copies the word into the allocated memory
        totalWords++;
        n->next = table[hash(dictWord)];// set next to point to the beginning of the list
        table[hash(dictWord)] = n;// set array to point to n
    }
    fclose(file);
    free(dictWord);
    return true;
}

unsigned int size(void){ // returns number of words in the dictionary
    return totalWords;
}

bool unload(void){ // unloads dictionary from memory, then frees memory
    node *tmp;
    node *cursor;
    for (int i = 0; i < N; i++){
        if (table[i] == NULL){
            continue;
        }
        cursor = table[i];
        tmp = cursor;
        while (cursor->next != NULL){
            cursor = cursor->next;
            free(tmp);
            tmp = cursor;
        }
        free(cursor);
    }
    return true;
}