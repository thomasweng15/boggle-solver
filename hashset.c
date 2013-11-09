/*
   hashset.c

   Source file for hashset data structure for boggle.

   Thomas Weng
*/

#include "hashset.h"

int hashFunc(int x, int y)
{
    return 5*y + x;
} 

void createHashSet(HashSet **hs)
{
    *hs = malloc(sizeof(HashSet));
    for (int i = 0; i < 25; i++) 
    {
	(*hs)->arr[i] = 0;
    }
}

bool lookUpHashValue(HashSet **hs, int index)
{
    if ((*hs)->arr[index]) 
    {
	return true;
    } 
    // if value is already in hash set, 
    else 
    {
	return false;
    }
}

bool insertHashValue(HashSet **hs, int x, int y)
{
    int index = hashFunc(x, y);
    if (!lookUpHashValue(hs, index))
    {
	(*hs)->arr[index] = 1;
	return true;
    }
    // if value is already in hash set, do not insert
    else
    {
	return false;
    }
}

bool removeHashValue(HashSet **hs, int x, int y)
{
    int index = hashFunc(x, y);
    if (lookUpHashValue(hs, index))
    {
	(*hs)->arr[index] = 0;
	return true;
    }
    // if value is not in hash set, nothing to remove
    else
    {
	return false;
    }
}

/*void destroyHashSet(HashSet **hs)
{

}*/
