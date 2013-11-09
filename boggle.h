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

bool initBoard(char ***bptr);
bool readBoard(char ***bptr);
bool freeBoard(char ***bptr);
void solveBoggle(LinkedList **LL, int x, int y, HashSet **HS);
