// Boggle Solver

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"
#include "hashset.h"

char* board[5][5] =
{
	{"a", "a", "a", "a", "a"},
	{"a", "a", "a", "a", "a"}, 
	{"a", "a", "a", "a", "a"},
	{"a", "a", "a", "a", "a"},
	{"a", "a", "a", "a", "a"}
}; 

void solveBoggle(LinkedList** LL, int x, int y, HashSet** visitedCoords)
{
	// if coordinates are out of range, stop
	if (x < 0 || y < 0 || x > 4 || y > 4)
	{
		return;
	}

	// if coordinates are already in HashSet, stop
	if (lookUpHashValue(visitedCoords, hashFunc(x, y)))
	{
		return;
	}

	// insert letter at position into LinkedList
	insertNode(LL, board[x][y]);

	// if new word is not a word or prefix to word, stop
	char* word = getWord(LL);
	//
	// otherwise, add coordinates to hashset
	insertHashValue(visitedCoords, x, y);

	// call solveboard in every direction (except nonvalid?)

}

int main() 
{
	LinkedList* LL;
	HashSet* visitedCoords;
	createLinkedList(&LL);
	createHashSet(&visitedCoords);

	solveBoggle(&LL, 0, 0, &visitedCoords);
}

