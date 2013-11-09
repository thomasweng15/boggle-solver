/*
    boggle.c

    Main source file for boggle solver.

    Thomas Weng
*/

#include "boggle.h"

int SIZE = 4; // size of board

int main() 
{
    // initialize board
    char **board;
    if (!initBoard(&board)) 
    {
	fprintf(stderr, "error initializing board\n");
	exit(EXIT_FAILURE);
    }

    // read in board 
    if (!readBoard(&board))
    {
	fprintf(stderr, "error reading in board\n");
	exit(EXIT_FAILURE);
    }

    // initialize data structures
    LinkedList *list;
    createLinkedList(&list);
    //HashSet *visitedCoords;
    //createHashSet(&visitedCoords);

    //solveBoggle(&LL, 0, 0, &visitedCoords);

    // cleanup
    destroyLinkedList(&list); 
    freeBoard(&board);
}

bool initBoard(char ***bptr) 
{
    char **board = *bptr;

    // initialize char * array
    board = malloc(SIZE * sizeof(char *));
    if (board == NULL)
	return false;

    // initialize char array for each char * pointer 
    for (int i = 0; i < SIZE; i++) 
    {
	board[i] = malloc(SIZE * sizeof(char));
	if (board[i] == NULL)
	    return false;

	for (int j = 0; j < SIZE; j++) 
	{
	    board[i][j] = ' ';
	}
    }

    *bptr = board;
    return true;
}

bool readBoard(char ***bptr)
{
    char **board = *bptr;

    // read from stdin and store characters in board until EOF
    char c;
    int row = 0;
    int col = 0;
    while ((c = getc(stdin)) != EOF)
    {
	if (c == '\n')
	{
	    row += 1;
	    col = 0;
	}
	else if (row == SIZE || col == SIZE)
	{
	    return false;
	}
	else 
	{
	    board[row][col] = c;
	    col += 1;
	}
    }

    *bptr = board;
    return true;         
}

bool freeBoard(char ***bptr)
{
    char **board = *bptr;

    // free every char * array in the char ** array
    for (int i = 0; i < SIZE; i++)
    {
	free(board[i]);
	board[i] = NULL;
    }

    // free the char ** array
    free(board);
    board = NULL;
    *bptr = board;
    return true;
}

/*
void solveBoggle(LinkedList **list, int x, int y, HashSet **visitedCoords)
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
    insertNode(list, board[x][y]);

    // if new word is not a word or prefix to word, stop
    char *word = getWord(list);
    //
    // otherwise, add coordinates to hashset
    insertHashValue(visitedCoords, x, y);

    // call solveboard in every direction (except nonvalid?)
}
*/
