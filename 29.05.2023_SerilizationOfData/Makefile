all: fillPatientData.out readPatients.out

fillPatientData.out: fillPatientData.c linkedlist.o patient.o fileUtil.h
	gcc fillPatientData.c linkedlist.o patient.o -o fillPatientData.out

readPatients.out: readPatients.c linkedlist.o patient.o fileUtil.h
	gcc readPatients.c linkedlist.o patient.o -o readPatients.out

patient.o: patient.h patient.c
	gcc -c patient.c -o patient.o

linkedlist.o: linkedlist.c linkedlist.h
	gcc -c linkedlist.c -o linkedlist.o

clean:
	rm -f *.o *.out