/*
   dict.c

   source files for dictionary related functions for boggle.

   Thomas Weng
*/

#include "dict.h"

// testing 
int main()
{
    // 97 - 122: a - z, 65 - 90: A - Z
    // turn all uppercase letters into lowercase letters
    char letter = 'A';
    if (letter < 97) {
	letter = letter + 32;
    }


    Trie *dict;
    createTrie(&dict);
    insertTNode(dict->children, letter, false);
    insertTNode((dict->children[0])->children, 'z', false);
    destroyTrie(&dict);
    return true;
}

bool createTrie(Trie **dict)
{
    *dict = malloc(sizeof(Trie));
    if (*dict == NULL) return false;
    (*dict)->children = malloc(sizeof(struct node *) * 26);
    for (int i = 0; i < 26; i++) 
    {
	(*dict)->children[i] = NULL;
    }
    return true;
}

bool destroyTrie(Trie **dict)
{
    deleteTNode((*dict)->children);
    free(*dict);
    return true;
}

bool deleteTNode(struct tnode **letters) 
{
    // input should never be NULL
    if (letters == NULL)
    {
	fprintf(stderr, "warning: attempting to free empty node\n");
	return false;
    }

    // depth first freeing of children
    for (int i = 0; i < 26; i++)
    {
	if (letters[i] != NULL)
	{
	    deleteTNode(letters[i]->children);
	    free(letters[i]);
	}
    }
    free(letters);

    return true;
}

bool insertTNode(struct tnode **letters, char letter, bool isWord) 
{
    // find index of new node and malloc space for it
    letters[letter - 97] = malloc(sizeof(struct tnode));
    if (letters[letter - 97] == NULL) 
    {
	fprintf(stderr, "malloc error\n");
	return false;	
    }

    // set data for new node 
    letters[letter - 97]->isWord = isWord;
    letters[letter - 97]->children = malloc(sizeof(struct tnode *) * 26);
    for (int i = 0; i < 26; i++)
    {
	letters[letter - 97]->children[i] = NULL;
    }

    return true;
}
