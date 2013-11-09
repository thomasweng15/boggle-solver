/*
    hashset.h

    header files for the hashset data structure for boggle.

    Thomas Weng
*/

#include <stdbool.h>

typedef struct hashset HashSet;

// TODO make variable
struct hashset
{
    int arr[25];
};

// TODO linear chaining
int hashFunc(int x, int y);
void createHashSet(HashSet** HS);
bool lookUpHashValue(HashSet** HS, int index);
bool insertHashValue(HashSet** HS, int x, int y);
bool removeHashValue(HashSet** HS, int x, int y);
//void destroyHashSet(HashSet** HS);
