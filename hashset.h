/*
    hashset.h

    header files for the hashset data structure for boggle.

    Thomas Weng
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct
{
    bool *arr;
} hashset;

bool updateSize(int width);
int hash(int x, int y);

bool createHashSet(hashset **hs);
bool destroyHashSet(hashset **hs);

bool lookUpHashVal(hashset **hs, int x, int y);
bool insertHashVal(hashset **hs, int x, int y);
bool removeHashVal(hashset **hs, int x, int y);
