/*
    fixdict.c

    fixing the dictionary file to format it correctly.

    Thomas Weng
*/

#include <stdlib.h>
#include <stdio.h>

int main() {
    FILE *original;
    FILE *new;
    char c;

    original = fopen("dict1.txt", "r");
    new = fopen("dict.txt", "w");
    
    while ((c = getc(original)) != EOF) {
        if (c == '\r') {
            ;
        } else {
            putc(c, new);
        }
    } 

    fclose(original);
    fclose(new);
    return EXIT_SUCCESS;
}
