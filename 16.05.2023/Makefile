all: library.out

linkedlist.o: linkedlist.c linkedlist.h
	gcc -c linkedlist.c -o linkedlist.o

library.out: library.c linkedlist.o
	gcc library.c linkedlist.o -o library.out

clean:
	rm -f *.out *.o