all: tests.out

linkedlist.o: linkedlist.c linkedlist.h
	gcc -c linkedlist.c -o linkedlist.o

tests.out: tests.c linkedlist.o
	gcc tests.c linkedlist.o -o tests.out

clean:
	rm -f *.out *.o