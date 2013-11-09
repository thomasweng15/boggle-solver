/*
   dict.h

   header files for dictionary related functions for boggle.

   Thomas Weng
*/

#include <stdlib.h>
#include <stdbool.h>

struct tnode
{
    char letter;	    // letter stored at node
    bool isWord;	    // true if tree from root to node is a word 
    struct tnode *children; // linked list of child nodes
};

typedef struct trie 
{
    struct tnode *children; // linked list of child nodes
} Trie;

bool createTrie(Trie **dict);
bool destroyTrie(Trie **dict);

//bool insertTNode(Trie **dict, char letter, bool isWord);
//bool insertWord(Trie **dict, char *word);
//bool loadTrie(Trie **dict);

//isPrefixToWord
//isWord
