/*
   dict.c

   source files for dictionary related functions for boggle.

   Thomas Weng
*/

#include "dict.h"

// testing 
int main()
{
    // 97 - 122: a - z, 65 - 90: A - Z

    Trie *dict;
    createTrie(&dict);
	loadTrie(&dict, "dict.txt");
	if (isPrefixToWord(&dict, "aard"))
    {
		printf("prefix hello worked!\n");
    }
	
    if (isWord(&dict, "aardvark"))
    {
		printf("isword works!\n");
    }
	
    destroyTrie(&dict);
    return true;
}

bool createTrie(Trie **dict)
{
    *dict = malloc(sizeof(Trie));
    if (*dict == NULL) return false;
    (*dict)->children = malloc(sizeof(struct node *) * 26);
    if ((*dict)->children == NULL)
    {
		fprintf(stderr, "malloc error\n");
		return false;
    }
    for (int i = 0; i < 26; i++) 
    {
		(*dict)->children[i] = NULL;
    }
    return true;
}

bool destroyTrie(Trie **dict)
{
    deleteTNode((*dict)->children);
    free(*dict);
    return true;
}

bool deleteTNode(struct tnode **letters) 
{
    // input should never be NULL
    if (letters == NULL)
    {
		fprintf(stderr, "warning: attempting to free empty node\n");
		return false;
    }
    // depth first freeing of children
    for (int i = 0; i < 26; i++)
    {
		if (letters[i] != NULL)
		{
	    	deleteTNode(letters[i]->children);
	    	free(letters[i]);
		}
    }
    free(letters);

    return true;
}

bool insertTNode(struct tnode **letters, char letter, bool isWord) 
{
    // find index of new node and malloc space for it
    letters[letter - 97] = malloc(sizeof(struct tnode));
    if (letters[letter - 97] == NULL) 
    {
		fprintf(stderr, "malloc error\n");
		return false;	
    }

    // set data for new node 
    letters[letter - 97]->isWord = isWord;
    letters[letter - 97]->children = malloc(sizeof(struct tnode *) * 26);
    if (letters[letter - 97]->children == NULL)
    {
		fprintf(stderr, "malloc error\n");
		return false;
    }
    for (int i = 0; i < 26; i++)
    {
		letters[letter - 97]->children[i] = NULL;
    }

    return true;
}

bool insertWord(Trie **dict, char *word)
{
    // loop through letters until last letter in word
    // walk though dict as we loop
    char letter;
    struct tnode **curr = (*dict)->children;
    for (int i = 0; i < strlen(word) - 1; i++)
    {
		// uppercase to lowercase
		if ((letter = word[i]) < 97) 
		{
	    	letter += 32;
		}

		// if letter does not exist, insert into dict
		if (curr[letter - 97] == NULL)
		{
	    	insertTNode(curr, letter, false);
		}
		curr = curr[letter - 97]->children;
    }
    // update variables for last letter
    if ((letter = word[strlen(word) - 1]) < 97) 
    {
		letter += 32;     
    }

    // if last letter exists, update isWord
    if (curr[letter - 97] != NULL)
    {
		curr[letter - 97]->isWord = true;
    }
    // create node otherwise
    else
    {
		insertTNode(curr, letter, true);
    }

    return true;
}

bool loadTrie(Trie **dict, char *file)
{
 	char *line;
    FILE *fp;

	if ((fp = fopen(file, "r")) == NULL) 
	{
        return false;
	}
	
	while ((line = getLine(fp)) != NULL) 
	{
		insertWord(dict, line);	// one word per line
	}

    return true;
}

// code from Stan Eisenstat's CS323
char *getLine(FILE *fp) 
{
    char *line;
	int size;
	int c, i;

	size = sizeof(double);
	line = malloc(size);
	for (i = 0; (c = getc(fp)) != EOF ; ) 
	{
		if (i == size - 1) 
		{
			size *= 2;						// Double allocation
			line = realloc(line, size);
		}
		line[i++] = c;
		if (c == '\n' || c == '\r') 		// Break on newline or carriage ret
		{	
			i = i - 1;
			break;
		}
	}

	if ((c == EOF || c == '\n' || c == '\r') && i == 0)	// Check immediate EOF
	{	
		free(line);
		return NULL;
	}
		 
	line[i++] = '\0';						// Terminate line
	line = realloc(line, i);				// Trim excess storage

	return (line);
}

bool isPrefixToWord(Trie **dict, char *str)
{
    char letter;
    struct tnode **curr = (*dict)->children;
    for (int i = 0; i < strlen(str); i++)
    {
		// uppercase to lowercase
		if ((letter = str[i]) < 97)
		{
	    	letter += 32;
		}	    
		// if letter does not exist, not a prefix. 
		if (curr[letter - 97] == NULL)
		{
	    	return false; 
	    	letter += 32;
		}	    
		// if letter does not exist, not a prefix. 
		if (curr[letter - 97] == NULL)
		{
	    	return false; 
		}
		curr = curr[letter - 97]->children;
    }
    return true;
}

bool isWord(Trie **dict, char *str)
{
    char letter;
    struct tnode **curr = (*dict)->children;
    for (int i = 0; i < strlen(str); i++)
    {
		// uppercase to lowercase
		if ((letter = str[i]) < 97)
		{
	    	letter += 32;
		}	    
		// if letter does not exist, not a word. 
		if (curr[letter - 97] == NULL)
		{
	    	return false; 
		}
		// if last character and isWord, return true
		else if (i == strlen(str) - 1 && curr[letter - 97]->isWord)
		{
	    	return true;
		}
		curr = curr[letter - 97]->children;
	}
	return true;
}







