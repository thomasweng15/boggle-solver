/*
    boggle.c

    Main source file for boggle solver.

    Thomas Weng
*/

#include "boggle.h"

int Size = 4; // size of grid
char **Grid; // boggle grid
trie *Dict;

int main(int argc, char *argv[]) 
{
    // TODO check argument for board size

    // initialize grid
    if (!initGrid()) 
    {
	fprintf(stderr, "error initializing grid\n");
	exit(EXIT_FAILURE);
    }

    // read in grid
    if (!readGrid())
    {
	fprintf(stderr, "error reading in grid\n");
	exit(EXIT_FAILURE);
    }

    // initialize data structures
    createTrie(&Dict);
    loadTrie(&Dict, "dict.txt");
    
    list *path;
    createLinkedList(&path);
    hashset *set;
    createHashSet(&set);
    trie *dups;
    createTrie(&dups);

    // call solve for every location on grid
    for (int i = 0; i < Size; i++) {
        for (int j = 0; j < Size; j++) {
            solve(i, j, &path, &set, &dups);
        }
    }

    // cleanup
    destroyTrie(&dups);
    destroyTrie(&Dict);
    destroyLinkedList(&path); 
    destroyHashSet(&set);
    freeGrid();
}

void solve(int x, int y, list **path, hashset **set, trie **dups)
{
    // if coordinates are out of range, stop
    if (x < 0 || y < 0 || x > Size - 1 || y > Size - 1) return;

    // if coordinates are already in hash set, stop
    if (lookUpHashVal(set, x, y)) return;

    insertNode(path, Grid[x][y]);

    char *word = getWord(path);
    if (isWord(&Dict, word) && !isWord(dups, word)) 
    {
        printf("%s\n", word);
        insertWord(dups, word);
    }

    if (isPrefixToWord(&Dict, word)) 
    {
        insertHashVal(set, x, y);

        // call solveboggle in every direction
        solve(x + 1, y, path, set, dups);
        solve(x - 1, y, path, set, dups); 
        solve(x, y + 1, path, set, dups);
        solve(x, y - 1, path, set, dups);
        solve(x + 1, y + 1, path, set, dups);
        solve(x + 1, y - 1, path, set, dups);
        solve(x - 1, y + 1, path, set, dups);
        solve(x - 1, y - 1, path, set, dups); 

        removeHashVal(set, x, y); 
    }

    removeNode(path);
}

bool initGrid() 
{
    // initialize char * array
    Grid = malloc(Size * sizeof(char *));
    if (Grid == NULL)
	return false;

    // initialize char array for each char * pointer 
    for (int i = 0; i < Size; i++) 
    {
	Grid[i] = malloc(Size * sizeof(char));
	if (Grid[i] == NULL)
	    return false;

	for (int j = 0; j < Size; j++) 
	{
	    Grid[i][j] = ' ';
	}
    }

    return true;
}

bool readGrid()
{
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
	else if (row == Size || col == Size)
	{
	    return false;
	}
	else 
	{
	    Grid[row][col] = c;
	    col += 1;
	}
    }

    return true;         
}

bool freeGrid(char ***bptr)
{
    // free every char * array in the char ** array
    for (int i = 0; i < Size; i++)
    {
	free(Grid[i]);
	Grid[i] = NULL;
    }

    // free the char ** array
    free(Grid);
    Grid = NULL;
    return true;
}

