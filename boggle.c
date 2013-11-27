/*
    boggle.c

    Main source file for boggle solver.

    Thomas Weng
*/

#include "boggle.h"

int SIZE = 4; // size of grid

int main() 
{
    // initialize grid
    char **grid;
    if (!initGrid(&grid)) 
    {
	fprintf(stderr, "error initializing grid\n");
	exit(EXIT_FAILURE);
    }

    // read in grid
    if (!readGrid(&grid))
    {
	fprintf(stderr, "error reading in grid\n");
	exit(EXIT_FAILURE);
    }

    // initialize data structures
    list *path;
    createLinkedList(&path);
    trie *dict;
    createTrie(&dict);
    loadTrie(&dict, "boggle.txt");
    hashset *set;
    createHashSet(&set);

    //solve(&board, 0, 0, &path, &coords, &dict);

    // cleanup
    destroyTrie(&dict);
    destroyLinkedList(&path); 
    destroyHashSet(&set);
    freeGrid(&grid);
}

void solve(char **grid, int x, int y, list **path, hashset **set, trie **dict)
{
    // if coordinates are out of range, stop
    if (x < 0 || y < 0 || x > SIZE - 1 || y > SIZE - 1) return;

    // if coordinates are already in hash set, stop
    if (lookUpHashVal(set, x, y)) return;

    // insert letter at position into linked list
    insertNode(path, grid[x][y]);

    // If word, print out
    char *word = getWord(path);
    if (isWord(dict, word)) printf("%s\n", word);

    // if prefix to word, add coordinate and continue
    if (isPrefixToWord(dict, word)) 
    {
        // add coordinate to hash set
        //insertHashVal(set, x, y);

        // call solveboggle in every direction, only one for now for testing
        solve(grid, x + 1, y, path, set, dict);

        // remove coordinate from hash set
        //removeHashValue(set, x, y); 
    }

    // remove letter from linked list
    // removeNode(list, grid[x][y]);   
}

bool initGrid(char ***bptr) 
{
    char **grid = *bptr;

    // initialize char * array
    grid = malloc(SIZE * sizeof(char *));
    if (grid == NULL)
	return false;

    // initialize char array for each char * pointer 
    for (int i = 0; i < SIZE; i++) 
    {
	grid[i] = malloc(SIZE * sizeof(char));
	if (grid[i] == NULL)
	    return false;

	for (int j = 0; j < SIZE; j++) 
	{
	    grid[i][j] = ' ';
	}
    }

    *bptr = grid;
    return true;
}

bool readGrid(char ***bptr)
{
    char **grid = *bptr;

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
	    grid[row][col] = c;
	    col += 1;
	}
    }

    *bptr = grid;
    return true;         
}

bool freeGrid(char ***bptr)
{
    char **grid = *bptr;

    // free every char * array in the char ** array
    for (int i = 0; i < SIZE; i++)
    {
	free(grid[i]);
	grid[i] = NULL;
    }

    // free the char ** array
    free(grid);
    grid = NULL;
    *bptr = grid;
    return true;
}

