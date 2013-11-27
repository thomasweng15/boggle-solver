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

bool removeNode(list **ls) 
{
    struct lnode *c, *p;

    // error if list is empty
    if (ls == NULL) 
    {
        fprintf(stderr, "attempting to delete from empty list\n");
        return false;
    }

    for (c = (*ls)->head; c != (*ls)->tail; c = c->next) 
    {
        p = c;
    }    

    free((*ls)->tail->word);
    free((*ls)->tail);
    (*ls)->tail = p;
    (*ls)->tail->next = NULL;
    return true;
}

char *getWord(list **ls)
{
    return (*ls)->tail->word;
}

/*
// testing
int main()
{
    list *ls;
    createLinkedList(&ls);
    insertNode(&ls, 'a');
    insertNode(&ls, 'h');
    printf("%s\n", getWord(&ls));
    removeNode(&ls);
    printf("%s\n", getWord(&ls));
    destroyLinkedList(&ls);
}
*/
