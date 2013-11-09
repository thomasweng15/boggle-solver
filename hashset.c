/*
   hashset.c

   Source file for hashset data structure for boggle.

   Thomas Weng
*/

#include <stdlib.h>
#include "hashset.h"

int hashFunc(int x, int y)
{
    return 5*y + x;
} 

void createHashSet(HashSet** HS)
{
    *HS = (HashSet *) malloc(sizeof(HashSet));
    for (int i = 0; i < 25; i++) 
    {
	(*HS)->arr[i] = 0;
    }
}

bool lookUpHashValue(HashSet** HS, int index)
{
    if ((*HS)->arr[index]) 
    {
	return true;
    } 
    // if value is already in hash set, 
    else 
    {
	return false;
    }
}

bool insertHashValue(HashSet** HS, int x, int y)
{
    int index = hashFunc(x, y);
    if (!lookUpHashValue(HS, index))
    {
	(*HS)->arr[index] = 1;
	return true;
    }
    // if value is already in hash set, do not insert
    else
    {
	return false;
    }
}

bool removeHashValue(HashSet** HS, int x, int y)
{
    int index = hashFunc(x, y);
    if (lookUpHashValue(HS, index))
    {
	(*HS)->arr[index] = 0;
	return true;
    }
    // if value is not in hash set, nothing to remove
    else
    {
	return false;
    }
}

/*void destroyHashSet(HashSet** HS)
{

}*/
