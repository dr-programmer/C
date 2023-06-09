#include <stdio.h>
#include <stdlib.h>

#include "structures.h"

int main()
{
    struct Employee director;
    director.workers = (struct Employee **)calloc(1, sizeof(struct Employee *));
    director.numberOfWorkers = 0;

    FILE *file = fopen("file.bin", "rb");
    if(file == NULL) {
        printf("Cannot open file");
        exit(0);
    }

    int numberOfWorkers;
    for(int m = 0;; m++) {
        fread(&numberOfWorkers, sizeof(int), 1, file);
        printf("Number of workers = %d \n", numberOfWorkers);
        if (numberOfWorkers == 0)break;
        *director.workers = (struct Employee *)realloc(*director.workers, (m+1)*sizeof(struct Employee));
        (director.workers[0]+m)->workers = (struct Employee **)calloc(1, sizeof(struct Employee *));
        (director.workers[0]+m)->numberOfWorkers = numberOfWorkers;
        director.numberOfWorkers++;
        *(director.workers[0]+m)->workers = (struct Employee *)calloc(numberOfWorkers, sizeof(struct Employee));
        for(int i = 0; i < numberOfWorkers; i++) {
            struct Employee *temp = (director.workers[0]+m)->workers[0];
            fread(&(temp+i)->name, sizeof(char), 100, file);
        }
        fread(&(director.workers[0]+m)->name, sizeof(char), 100, file);
    }
    fread(&director.name, sizeof(char), 100, file);

    struct Employee *test = director.workers[0]->workers[0];
    printf("\nWorker name = %s \n", (test+1)->name);
    printf("Manager name = %s \n", director.workers[0]->name);
    printf("Director name = %s \n", director.name);

    printf("\n%s \n", director.name);
    for(int i = 0; i < director.numberOfWorkers; i++) {
        printf("    %s \n", (director.workers[0]+i)->name);
        for(int j = 0; j < (director.workers[0]+i)->numberOfWorkers; j++) {
            test = (director.workers[0]+i)->workers[0];
            printf("        %s \n", (test+j)->name);
        }
        free(*(director.workers[0]+i)->workers);
        free((director.workers[0]+i)->workers);
    }

    free(*director.workers);
    free(director.workers);
    
    fclose(file);

    return 0;
}