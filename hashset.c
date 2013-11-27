/*
   hashset.c

   Source file for hashset data structure for boggle.

   Thomas Weng
*/

#include "hashset.h"

int WIDTH = 4;

bool updateSize(int width)
{
    WIDTH = width;
    return true;
}

int hash(int x, int y)
{
    return WIDTH*x + y; // note: only works for size < 10
} 

bool createHashSet(hashset **hs)
{
    *hs = malloc(sizeof(hashset));
    if (*hs == NULL) return false;
    (*hs)->arr = calloc(WIDTH*WIDTH, sizeof(bool));
    if ((*hs)->arr == NULL) return false;
    return true;
}

bool destroyHashSet(hashset **hs)
{
    free((*hs)->arr);
    free(*hs);
    return true;
}

bool lookUpHashVal(hashset **hs, int x, int y)
{
    return (*hs)->arr[hash(x, y)];
}

bool insertHashVal(hashset **hs, int x, int y)
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

bool removehashVal(hashset **hs, int x, int y) 
{
    if ((*hs)->arr[hash(x,y)] == true) 
    {
        (*hs)->arr[hash(x,y)] = false;
        return true;
    }
    else
    {
        fprintf(stderr, "hashset: value already doesn't exist\n");
        return false;
    }
}

// testing
/*
int main()
{
    hashset *hs;
    createHashSet(&hs);
    updateHashVal(&hs, 1, 1);
    if (lookUpHashVal(&hs, 1, 1))
    {
	printf("YES\n");
    }
    destroyHashSet(&hs);
}
*/
