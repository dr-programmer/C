all: main.out

linkedlist.o: linkedlist.c linkedlist.h
	gcc -c linkedlist.c -o linkedlist.o

main.out: main.c linkedlist.o
	gcc main.c linkedlist.o -o main.out

clean:
	rm -f *.out *.o