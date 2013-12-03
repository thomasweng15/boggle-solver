CC = gcc 
CFLAGS = -g3 -std=c99 -pedantic -Wall

All: boggle 

boggle: boggle.o linkedlist.o hashset.o dict.o
	${CC} ${CFLAGS} -o $@ $^

boggle.o: boggle.h linkedlist.o hashset.o dict.o

linkedlist.o: linkedlist.h

hashset.o: hashset.h

dict.o: dict.h


### testing
linkedlist: linkedlist.c
	${CC} ${CFLAGS} -o $@ $^

hashset: hashset.c
	${CC} ${CFLAGS} -o $@ $^

dict: dict.c
	${CC} ${CFLAGS} -o $@ $^

### fixing the dictionary file
fixdict: fixdict.c dict.o
	${CC} ${CFLAGS} -o $@ $^
