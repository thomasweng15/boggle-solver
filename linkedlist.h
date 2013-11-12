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

typedef struct linkedlist
{
    struct lnode *head;
    struct lnode *tail;
} LinkedList;

bool createLinkedList(LinkedList **list);
bool destroyLinkedList(LinkedList **list);

bool insertNode(LinkedList **list, char letter);
char *getWord(LinkedList **list);
