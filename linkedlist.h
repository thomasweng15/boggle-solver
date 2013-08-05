// ADT for headless linkedlist.
#include <stdbool.h>
#include <string.h>

typedef struct node Node;

struct node 
{
	char* word;
	Node* next;
};

typedef struct linkedlist LinkedList;

struct linkedlist
{
	Node* head;
	Node* tail;
};

void createLinkedList(LinkedList** LL);
void insertNode(LinkedList** LL, char* letter);
bool deleteLastNode(LinkedList** LL);
void destroyLinkedList(LinkedList** LL);
char* getWord(LinkedList** LL);
// searchNode