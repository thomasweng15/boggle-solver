/*
   dict.h

   header files for dictionary related functions for boggle.

   Thomas Weng
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// index of node indicates character
struct tnode
{
    bool isWord;		// true if tree from root to node is a word 
    struct tnode **children;	// array of child nodes
};

typedef struct 
{
    struct tnode **children;	// array of child nodes
} trie;

bool createTrie(trie **dict);
bool destroyTrie(trie **dict);
bool deleteTNode(struct tnode **letters);

bool insertTNode(struct tnode **letters, char letter, bool isWord);
bool insertWord(trie **dict, char *word);
bool loadTrie(trie **dict, char *file);
char *getLine(FILE *fp);

bool isPrefixToWord(trie **dict, char *str);
bool isWord(trie **dict, char *str);
