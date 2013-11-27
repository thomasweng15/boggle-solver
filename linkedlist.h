/*
    linkedlist.h

    header files for linkedlist data structure for boggle.

    Thomas Weng
*/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct lnode 
{
    char *word;
    struct lnode *next;
};

typedef struct 
{
    struct lnode *head;
    struct lnode *tail;
} list;

bool createLinkedList(list **ls);
bool destroyLinkedList(list **ls);

bool insertNode(list **ls, char letter);
char *getWord(list **ls);
