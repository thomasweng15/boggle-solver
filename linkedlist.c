/*
   linkedlist.c

   Source files for linkedlist data structure for boggle.

   Thomas Weng
*/

#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"

int main()
{
    LinkedList *list;
    createLinkedList(&list);
    insertNode(&list, 'a');
    insertNode(&list, 'h');
    printf("%s\n", getWord(&list));
    destroyLinkedList(&list);
}

bool createLinkedList(LinkedList **list) 
{
    *list = malloc(sizeof(LinkedList));
    if (*list == NULL) return false;
    (*list)->head = NULL;
    (*list)->tail = NULL;
    return true;
}

bool destroyLinkedList(LinkedList **list)
{
    struct lnode *curr, *prev;
    curr = (*list)->head;
    while (curr != NULL)
    {
	free(curr->word);
	prev = curr;
	curr = curr->next;	
	free(prev);
    }
    free(*list);
    *list = NULL;
    return true;
}

bool insertNode(LinkedList **list, char letter)
{
    // create new lnode
    struct lnode *new;
    new = malloc(sizeof(struct lnode));
    if (new == NULL) return false;
    new->next = NULL;

    // make word for lnode
    if ((*list)->tail == NULL)
    {
	new->word = malloc(sizeof(char) + 1);
	if (new->word == NULL) return false;
	new->word[0] = letter;
	new->word[1] = '\0';
    }
    else
    {
	int oldLen = strlen(((*list)->tail)->word);
	new->word = strdup(((*list)->tail)->word);
	new->word = realloc(new->word, oldLen + sizeof(char) + 1);
	if (new->word == NULL) return false;
	new->word[oldLen] = letter;
	new->word[oldLen + 1] = '\0';
    }

    // insert new node into list
    if ((*list)->tail != NULL) 
    {
	((*list)->tail)->next = new;
    }
    // if tail node is NULL, we are inserting into an empty list
    else
    {
	(*list)->head = new;
    }
    (*list)->tail = new;
    
    return true;
}

char *getWord(LinkedList **list)
{
    return (*list)->tail->word;
}


