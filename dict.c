/*
   dict.c

   source files for dictionary related functions for boggle.

   Thomas Weng
*/

#include "dict.h"

// testing 
int main()
{
    Trie *dict;
    createTrie(&dict);
    destroyTrie(&dict);
    return true;
}

bool createTrie(Trie **dict)
{
    *dict = malloc(sizeof(Trie));
    if (*dict == NULL) return false;
    (*dict)->children = NULL;
    return true;
}

bool destroyTrie(Trie **dict)
{
    free(*dict);
    return true;
}

