/*
    linkedlist.h

    header files for linkedlist data structure for boggle.

    Thomas Weng
*/

#include <stdbool.h>
#include <string.h>

typedef struct lnode *LNode;

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

void createLinkedList(LinkedList **list);
void insertNode(LinkedList **list, char *letter);
bool deleteLastNode(LinkedList **list);
void destroyLinkedList(LinkedList **list);
char *getWord(LinkedList **list);
// searchNode
