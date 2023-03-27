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
        arr->buffer = (int *)realloc(arr->buffer, arr->capacity * sizeof(int));
        ASSERT_ALLOC_MEMORY(arr->buffer)
    }
    else if(newsize <= arr->capacity/2){
        arr->capacity /= 2;
        arr->buffer = (int *)realloc(arr->buffer, arr->capacity * sizeof(int));
        ASSERT_ALLOC_MEMORY(arr->buffer)
    }
    arr->size = newsize;
}

DynamicArray init(int capacity) {
    DynamicArray arr;
    arr.capacity = capacity;
    arr.size = 0;
    arr.buffer = (int *)calloc(capacity, sizeof(int));

    return arr;
}

void pushback(DynamicArray *arr, int value) {
    int newsize = arr->size + 1;
    resize(arr, newsize);
    arr->buffer[newsize - 1] = value;
}

int popback(DynamicArray *arr) {
    if (arr->size == 0){
        return -1;
    }
    int result = arr->buffer[arr->size - 1];
    arr->buffer[arr->size - 1] = 0;
    int newsize = arr->size - 1;
    resize(arr, newsize);

    return result;
}

void pushfront(DynamicArray *arr, int value) {
    int newsize = arr->size + 1;
    resize(arr, newsize);
    for(int i = (arr->size - 1); i > 0; i--){
        arr->buffer[i] = arr->buffer[i-1];
    }
    arr->buffer[0] = value;
}

int popfront(DynamicArray *arr) {
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

void setelement(DynamicArray *arr, int index, int value) {
    arr->buffer[index] = value;
}

int getelement(DynamicArray *arr, int index) {
    return arr->buffer[index];
}

void release(DynamicArray *arr) {
    ASSERT_ALLOC_MEMORY(arr)
    free(arr->buffer);
}