/*
   hashset.c

   Source file for hashset data structure for boggle.

   Thomas Weng
*/

#include "hashset.h"

int SIZE = 4;

int main()
{
    HashSet *hs;
    createHashSet(&hs);
    updateHashVal(&hs, 1, 1);
    if (lookUpHashVal(&hs, 1, 1))
    {
	printf("YES\n");
    }
    destroyHashSet(&hs);
}

bool updateSize(int size)
{
    SIZE = size;
    return true;
}

int hash(int x, int y)
{
    return SIZE*x + y; // only works for size < 10
} 

bool createHashSet(HashSet **hs)
{
    *hs = malloc(sizeof(struct hashset));
    if (*hs == NULL) return false;
    (*hs)->arr = calloc(SIZE*SIZE, sizeof(bool));
    if ((*hs)->arr == NULL) return false;
    return true;
}

bool destroyHashSet(HashSet **hs)
{
    free((*hs)->arr);
    free(*hs);
    return true;
}

bool lookUpHashVal(HashSet **hs, int x, int y)
{
    return (*hs)->arr[hash(x, y)];
}

bool updateHashVal(HashSet **hs, int x, int y)
{
    if ((*hs)->arr[hash(x,y)] == false)
    {
	(*hs)->arr[hash(x,y)] = true;
	return true;
    }	
    else
    {
	fprintf(stderr, "hashset: already has value\n");
	return false;
    }
}

