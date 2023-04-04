#include <stdio.h>

#include "dynamicarr.h"

void printdynarr(DynamicArray *arr) {
    for(int i = 0; i < arr->size; i++){
        double currel = getelement(arr, i);
        printf("%lf ", currel);
    }
    printf("\n");
}

int main()
{
    DynamicArray arr = init(3);
    printdynarr(&arr);

    pushback(&arr, 4);
    pushback(&arr, 7);
    pushback(&arr, 5);
    pushback(&arr, 3);

    printdynarr(&arr);

    popback(&arr);
    printdynarr(&arr);

    pushfront(&arr, 11);
    pushfront(&arr, 22);
    pushfront(&arr, 33);
    printdynarr(&arr);

    popfront(&arr);
    popfront(&arr);
    popfront(&arr);
    printdynarr(&arr);

    setelement(&arr, 2, 6);
    printdynarr(&arr);

    pop(&arr, 1);
    printdynarr(&arr);

    printf("The value 6 is on index: %d \n", getindex(&arr, 6));

    release(&arr);
    printdynarr(&arr);

    return 0;
}