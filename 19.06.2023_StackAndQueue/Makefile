all: stack.out

linkedlist.o: linkedlist.c linkedlist.h
	gcc -c linkedlist.c -o linkedlist.o

stack.out: stack.c linkedlist.o
	gcc stack.c linkedlist.o -o stack.out

clean:
	rm -f *.out *.o