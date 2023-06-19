all: queue.out

linkedlist.o: linkedlist.c linkedlist.h
	gcc -c linkedlist.c -o linkedlist.o

queue.out: queue.c linkedlist.o
	gcc queue.c linkedlist.o -o queue.out

clean:
	rm -f *.out *.o