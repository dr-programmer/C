robot.out: bitstate.o bitstate.h robot.c bitstate.c
	gcc robot.c bitstate.o -o robot.out

bitstate.o: bitstate.c bitstate.h
	gcc -c bitstate.c -o bitstate.o

clean:
	rm -f *.o *.out