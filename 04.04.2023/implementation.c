#include <stdio.h>
#include <stdlib.h>

#include "dynamicarr.h"

void printdynarr(DynamicArray *arr) {
    for(int i = 0; i < arr->size; i++){
        printf("%.0lf ", getelement(arr, i));
    }
    printf("\n");
}

int main()
{
    DynamicArray arr = init(5);

    while(1) {
        int option;
        printf("1: Add donor; 2: Remove donor; 3: Show all donors; 4: Close \n");
        scanf("%d", &option);

        switch(option){
            case 1: {
                double egn;
                printf("Please wright the EGN of the donor: ");
                scanf("%lf", &egn);
                pushback(&arr, egn);
                break;
            }
            case 2: {
                double egn;
                printf("Please wright the EGN of the donor: ");
                scanf("%lf", &egn);
                pop(&arr, getindex(&arr, egn));
                break;
            }
            case 3: {
                printdynarr(&arr);
                break;
            }
            default: {
                release(&arr);
                exit(-1);
            }
        }
    }

    return 0;
}