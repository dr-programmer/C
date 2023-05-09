all: tests.out

duallinkedlist.o: duallinkedlist.c duallinkedlist.h
	gcc -c duallinkedlist.c -o duallinkedlist.o

tests.out: tests.c duallinkedlist.o
	gcc tests.c duallinkedlist.o -o tests.out

clean:
	rm -f *.out *.o
