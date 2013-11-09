/*
   linkedlist.c

   Source files for linkedlist data structure for boggle.

   Thomas Weng
*/

#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"


void createLinkedList(LinkedList **list) 
{
    *list = malloc(sizeof(LinkedList));
    (*list)->head = NULL;
    (*list)->tail = NULL;
}

void insertNode(LinkedList **list, char *letter)
{
    struct lnode *current;
    current = malloc(sizeof(struct lnode));
    current->next = NULL;
    if ((*list)->tail == NULL) 
    {
    	current->word = malloc(strlen(letter) + 1);
    	strcpy(current->word, letter);
    }
    else 
    {	
    	current->word = malloc(strlen((*list)->tail->word) + 1);
    	strcpy(current->word, (*list)->tail->word);
    	strcpy(current->word + strlen(current->word), letter);
    }	
	
    // if this is the first node added to the list, set head to node
    if ((*list)->head == NULL) 
    {
    	(*list)->head = current;
    	(*list)->tail = current;
    } 
    // otherwise, iterate through list and append to last node.
    else 
    {
    	struct lnode *index;
    	index = (*list)->head;
    	while (index->next)
    	{
	    index = index->next;
    	}
    	index->next = current;
    	(*list)->tail = current;
    }
}

bool deleteLastNode(LinkedList **list)
{
    struct lnode *current;
    struct lnode *previous;
    current = (*list)->head;
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
	(*list)->tail = previous;
    }
    // if last node is the first node, reset tail pointer
    else 
    {
	(*list)->head = NULL;
	(*list)->tail = NULL;
    }
    return true;
}

void destroyLinkedList(LinkedList **list)
{
    while (1)
    {
	if ((*list)->head == NULL)
	{
	    break;
	}
	deleteLastNode(list);
    }
    free(*list);
    *list = NULL;
}

char *getWord(LinkedList **list)
{
    return (*list)->tail->word;
}


