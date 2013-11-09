/*
   dict.c

   source files for dictionary related functions for boggle.

   Thomas Weng
*/

#include "dict.h"

bool createTrie(Trie **dict)
{
    *dict = malloc(sizeof(Trie));
    if (!dict) return false;
    (*dict)->children = NULL;
    return true;
}

bool destroyTrie(Trie **dict)
{
    free(dict);
    return true;
}

