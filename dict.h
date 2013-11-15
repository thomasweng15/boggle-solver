/*
   dict.h

   header files for dictionary related functions for boggle.

   Thomas Weng
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// index of node indicates character
struct tnode
{
    bool isWord;		// true if tree from root to node is a word 
    struct tnode **children;	// array of child nodes
};

typedef struct trie 
{
    struct tnode **children;	// array of child nodes
} Trie;

bool createTrie(Trie **dict);
bool destroyTrie(Trie **dict);
bool deleteTNode(struct tnode **letters);

bool insertTNode(struct tnode **letters, char letter, bool isWord);
//bool insertWord(Trie **dict, char *word);
//bool loadTrie(Trie **dict);

//isPrefixToWord
//isWord
