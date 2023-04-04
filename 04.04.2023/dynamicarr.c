#include <stdio.h>
#include <stdlib.h>

#include "dynamicarr.h"

#define ASSERT_ALLOC_MEMORY(PTR) \
    if ((PTR) == NULL) { \
        printf("Error allocating memory! \n"); \
        exit(-1); \
    }

static void resize(DynamicArray *arr, int newsize) {
    if(newsize > arr->capacity){
        arr->capacity *= 2;
        arr->buffer = (double *)realloc(arr->buffer, arr->capacity * sizeof(double));
        ASSERT_ALLOC_MEMORY(arr->buffer)
    }
    else if(newsize <= arr->capacity/2){
        arr->capacity /= 2;
        arr->buffer = (double *)realloc(arr->buffer, arr->capacity * sizeof(double));
        ASSERT_ALLOC_MEMORY(arr->buffer)
    }
    arr->size = newsize;
}

DynamicArray init(int capacity) {
    DynamicArray arr;
    arr.capacity = capacity;
    arr.size = 0;
    arr.buffer = (double *)calloc(capacity, sizeof(double));

    return arr;
}

void pushback(DynamicArray *arr, double value) {
    int newsize = arr->size + 1;
    resize(arr, newsize);
    arr->buffer[newsize - 1] = value;
}

double popback(DynamicArray *arr) {
    if (arr->size == 0){
        return -1;
    }
    int result = arr->buffer[arr->size - 1];
    arr->buffer[arr->size - 1] = 0;
    int newsize = arr->size - 1;
    resize(arr, newsize);

    return result;
}

void pushfront(DynamicArray *arr, double value) {
    int newsize = arr->size + 1;
    resize(arr, newsize);
    for(int i = (arr->size - 1); i > 0; i--){
        arr->buffer[i] = arr->buffer[i-1];
    }
    arr->buffer[0] = value;
}

double popfront(DynamicArray *arr) {
    if (arr->size == 0){
        return -1;
    }
    int result = arr->buffer[0];
    for(int i = 0; i < arr->size - 1; i++){
        arr->buffer[i] = arr->buffer[i+1];
    }
    arr->buffer[arr->size - 1] = 0;
    int newsize = arr->size - 1;
    resize(arr, newsize);

    return result;
}

double pop(DynamicArray *arr, int index) {
    if (index == 0)return popfront(arr);
    else if (index == arr->size - 1)return popback(arr);

    double result = arr->buffer[index];
    int newsize = arr->size - 1;
    for(int i = index; i < newsize; i++){
        arr->buffer[i] = arr->buffer[i+1];
    }
    resize(arr, newsize);

    return result;
}

void setelement(DynamicArray *arr, int index, double value) {
    arr->buffer[index] = value;
}

double getelement(DynamicArray *arr, int index) {
    return arr->buffer[index];
}

int getindex(DynamicArray *arr, double value) {
    for(int i = 0; i < arr->size; i++){
        if (arr->buffer[i] == value)return i;
    }
    return -1;
}

void release(DynamicArray *arr) {
    ASSERT_ALLOC_MEMORY(arr)
    arr->size = 0;
    arr->capacity = 0;
    free(arr->buffer);
}