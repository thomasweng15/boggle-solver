/*
   linkedlist.c

   Source files for linkedlist data structure for boggle.

   Thomas Weng
*/

#include "linkedlist.h"

bool createLinkedList(list **ls) 
{
    *ls = malloc(sizeof(list));
    if (*ls == NULL) return false;
    (*ls)->head = NULL;
    (*ls)->tail = NULL;
    return true;
}

bool destroyLinkedList(list **ls)
{
    struct lnode *curr, *prev;
    curr = (*ls)->head;
    while (curr != NULL)
    {
	free(curr->word);
	prev = curr;
	curr = curr->next;	
	free(prev);
    }
    free(*ls);
    *ls = NULL;
    return true;
}

bool insertNode(list **ls, char letter)
{
    // create new lnode
    struct lnode *new;
    new = malloc(sizeof(struct lnode));
    if (new == NULL) return false;
    new->next = NULL;

    // make word for lnode
    if ((*ls)->tail == NULL)
    {
	new->word = malloc(sizeof(char) + 1);
	if (new->word == NULL) return false;
	new->word[0] = letter;
	new->word[1] = '\0';
    }
    else
    {
	int oldLen = strlen(((*ls)->tail)->word);
	new->word = malloc(oldLen + sizeof(char) + 1);
	if (new->word == NULL) return false;
	strncpy(new->word, ((*ls)->tail)->word, oldLen);
	new->word[oldLen] = letter;
	new->word[oldLen + 1] = '\0';
    }

    // insert new node into list
    if ((*ls)->tail != NULL) 
    {
	((*ls)->tail)->next = new;
    }
    // if tail node is NULL, we are inserting into an empty list
    else
    {
	(*ls)->head = new;
    }
    (*ls)->tail = new;
    
    return true;
}

char *getWord(list **ls)
{
    return (*ls)->tail->word;
}

// testing
/*
int main()
{
    LinkedList *list;
    createLinkedList(&list);
    insertNode(&list, 'a');
    insertNode(&list, 'h');
    printf("%s\n", getWord(&list));
    destroyLinkedList(&list);
}
*/
