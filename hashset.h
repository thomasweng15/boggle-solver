/*
    hashset.h

    header files for the hashset data structure for boggle.

    Thomas Weng
*/

#include <stdlib.h>
#include <stdbool.h>

// TODO make variable
typedef struct hashset
{
    int arr[25];
} HashSet;

// TODO linear chaining
int hashFunc(int x, int y);
void createHashSet(HashSet **hs);
bool lookUpHashValue(HashSet **hs, int index);
bool insertHashValue(HashSet **hs, int x, int y);
bool removeHashValue(HashSet **hs, int x, int y);
//void destroyHashSet(HashSet **hs);
