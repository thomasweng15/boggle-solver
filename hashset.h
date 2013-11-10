/*
    hashset.h

    header files for the hashset data structure for boggle.

    Thomas Weng
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct hashset
{
    bool *arr;
} HashSet;

bool updateSize(int size);
int hash(int x, int y);

bool createHashSet(HashSet **hs);
bool destroyHashSet(HashSet **hs);

bool lookUpHashVal(HashSet **hs, int x, int y);
bool updateHashVal(HashSet **hs, int x, int y);
