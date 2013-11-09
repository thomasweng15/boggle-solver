/*
   linkedlist.c

   Source files for linkedlist data structure for boggle.

   Thomas Weng
*/

#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"


void createLinkedList(LinkedList** LL) 
{
    *LL = (LinkedList *) malloc(sizeof(LinkedList));
    (*LL)->head = NULL;
    (*LL)->tail = NULL;
}

void insertNode(LinkedList** LL, char* letter)
{
    Node* current;
    current = (Node *) malloc(sizeof(Node));
    current->next = NULL;
    if ((*LL)->tail == NULL) 
    {
    	current->word = malloc(strlen(letter) + 1);
    	strcpy(current->word, letter);
    }
    else 
    {	
    	current->word = malloc(strlen((*LL)->tail->word) + 1);
    	strcpy(current->word, (*LL)->tail->word);
    	strcpy(current->word + strlen(current->word), letter);
    }	
	
    // if this is the first node added to the list, set head to node
    if ((*LL)->head == NULL) 
    {
    	(*LL)->head = current;
    	(*LL)->tail = current;
    } 
    // otherwise, iterate through list and append to last node.
    else 
    {
    	Node* index;
    	index = (*LL)->head;
    	while (index->next)
    	{
	    index = index->next;
    	}
    	index->next = current;
    	(*LL)->tail = current;
    }
}

bool deleteLastNode(LinkedList** LL)
{
    Node* current;
    Node* previous;
    current = (*LL)->head;
    previous = NULL;

    if (current == NULL)
    {
	return false;
    }

    while (current->next)
    {
	previous = current;
	current = current->next;
    }
    free(current);

    // if last node is not the first node, update pointers
    if (previous != NULL)
    {
	previous->next = NULL;
	(*LL)->tail = previous;
    }
    // if last node is the first node, reset tail pointer
    else 
    {
	(*LL)->head = NULL;
	(*LL)->tail = NULL;
    }
    return true;
}

void destroyLinkedList(LinkedList** LL)
{
    while (1)
    {
	if ((*LL)->head == NULL)
	{
	    break;
	}
	deleteLastNode(LL);
    }
    free(*LL);
    *LL = NULL;
}

char* getWord(LinkedList** LL)
{
    return (*LL)->tail->word;
}


