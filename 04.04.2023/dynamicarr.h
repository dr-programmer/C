#ifndef DYNAMICARR_H
#define DYNAMICARR_H

typedef struct {
    double *buffer;
    unsigned int capacity;
    unsigned int size;
} DynamicArray;

DynamicArray init(int capacity);
void pushback(DynamicArray *arr, double value);
double popback(DynamicArray *arr);

void pushfront(DynamicArray *arr, double value);
double popfront(DynamicArray *arr);

double pop(DynamicArray *arr, int index);

void setelement(DynamicArray *arr, int index, double value);
double getelement(DynamicArray *arr, int index);
int getindex(DynamicArray *arr, double value);

void release(DynamicArray *arr);

#endif