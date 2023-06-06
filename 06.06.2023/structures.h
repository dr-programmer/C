#ifndef STRUCTURES_H
#define STRUCTURES_H

struct Employee{
    char name[100];
    int numberOfWorkers;
    struct Employee **workers;
};

#endif