#ifndef PROCESSES_H
#define PROCESSES_H

#define MAX_SIZE 5

struct Process{
    unsigned int id;
    char name[31];
};

extern struct Process processes[5];
extern char processescount;

static unsigned int nextprocessid();
unsigned int createnewprocess(char *name);
void stopprocess(unsigned int thisid);

#endif