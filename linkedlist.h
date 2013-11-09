/*
    linkedlist.h

    header files for linkedlist data structure for boggle.

    Thomas Weng
*/

#include <stdbool.h>
#include <string.h>

typedef struct node Node;

struct node 
{
    char* word;
    Node* next;
};

typedef struct linkedlist
{
    Node* head;
    Node* tail;
} LinkedList;

void createLinkedList(LinkedList** LL);
void insertNode(LinkedList** LL, char* letter);
bool deleteLastNode(LinkedList** LL);
void destroyLinkedList(LinkedList** LL);
char* getWord(LinkedList** LL);
// searchNode
