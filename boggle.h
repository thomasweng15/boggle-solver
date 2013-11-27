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

bool initGrid(char ***bptr);
bool readGrid(char ***bptr);
bool freeGrid(char ***bptr);
void solve(char **grid, int x, int y, list **path, hashset **set, trie **dict);
