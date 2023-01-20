all: safeadd.out safesubtract.out safemultiply.out safedivide.out

safeadd.out: safeint.o
	gcc safeadd.c safeint.o -o safeadd.out

safesubtract.out: safeint.o
	gcc safesubtract.c safeint.o -o safesubtract.out

safemultiply.out: safeint.o
	gcc safemultiply.c safeint.o -o safemultiply.out

safedivide.out: safeint.o
	gcc safedivide.c safeint.o -o safedivide.out

safeint.o:
	gcc -c safeint.c -o safeint.o

clean:
	rm -f *.o *.out