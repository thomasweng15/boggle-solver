/*
    fixdict.c

    fixing the dictionary file to format it correctly.

    Thomas Weng
*/

#include <stdlib.h>
#include <stdio.h>
#include "dict.h"

int main() {
    FILE *original, *new;
    char *line;

    original = fopen("dict1.txt", "r");
    new = fopen("dict.txt", "w");
    
    while ((line = getLine(original)) != NULL) {
        if (strlen(line) > 2) {
            fprintf(new, line);
            fprintf(new, "\n");
        }
        free(line);
    } 

    fclose(original);
    fclose(new);
    return EXIT_SUCCESS;
}
