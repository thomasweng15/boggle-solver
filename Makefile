CC = gcc 
CFLAGS = -g3 -std=c99 -pedantic -Wall

boggle: src/boggle.o src/linkedlist.o src/hashset.o
	${CC} ${CFLAGS} -o $@ $^

boggle.o: src/boggle.h linkedlist.o hashset.o

linkedlist.o: src/linkedlist.h

hashset.o: src/hashset.h