/* 
   boggle.h

   header file for main boggle functions.

   Thomas Weng
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "linkedlist.h"
#include "hashset.h"
#include "dict.h"

bool initGrid();
bool readGrid();
bool freeGrid();
void solve(int x, int y, list **path, hashset **set, trie **dict, trie **dups);
