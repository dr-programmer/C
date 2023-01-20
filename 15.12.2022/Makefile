main.out: quadraticroots.o main.c
	gcc main.c quadraticroots.o -lm -o main.out

quadraticroots.o: quadraticroots.c quadraticroots.h
	gcc -c quadraticroots.c -o quadraticroots.o

clean:
	rm -f *.o *.out