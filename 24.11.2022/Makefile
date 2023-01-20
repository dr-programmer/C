all: help.out mystrings.o strlength.out strconcat.out strcompare.out

help.out:
	gcc main.c -o help.out

mystrings.o:
	gcc -c mystrings.c -o mystrings.o

strlength.out:
	gcc strlength.c mystrings.o -o strlength.out

strconcat.out:
	gcc strconcat.c mystrings.o -o strconcat.out

strcompare.out:
	gcc strcompare.c mystrings.o -o strcompare.out

clean:
	rm -f *.out *.o