CC = gcc 
CFLAGS = -g3 -std=c99 -pedantic -Wall

boggle: boggle.o linkedlist.o hashset.o dict.o
	${CC} ${CFLAGS} -o $@ $^

boggle.o: boggle.h linkedlist.o hashset.o dict.o

linkedlist.o: linkedlist.h

hashset.o: hashset.h

dict.o: dict.h
