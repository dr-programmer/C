#include <stdio.h>
#include <stdlib.h>

#include "structures.h"

int main()
{
    struct Employee workers0[3];
    struct Employee workers1[3];
    struct Employee managers[2];
    managers[0].workers = &workers0;
    managers[1].workers = &workers1;
    struct Employee director;
    director.workers = &managers;

    FILE *file = fopen("file.bin", "rb");
    if(file == NULL) {
        printf("Cannot open file");
        exit(0);
    }

    int numberOfWorkers;
    fread(&numberOfWorkers, sizeof(int), 1, file);
    printf("Number of workers = %d \n", numberOfWorkers);
    for(int i = 0; i < numberOfWorkers; i++) {
        fread(&workers0[i].name, sizeof(char), 100, file);
    }
    fread(&managers[0].name, sizeof(char), 100, file);

    fread(&numberOfWorkers, sizeof(int), 1, file);
    printf("Number of workers = %d \n", numberOfWorkers);
    for(int i = 0; i < numberOfWorkers; i++) {
        fread(&workers1[i].name, sizeof(char), 100, file);
    }
    fread(&managers[1].name, sizeof(char), 100, file);
    
    fread(&numberOfWorkers, sizeof(int), 1, file);
    printf("Number of workers = %d \n", numberOfWorkers);
    if(numberOfWorkers == 0) {
        fread(&director.name, sizeof(char), 100, file);
    }

    printf("\nWorker name = %s \n", workers0[1].name);
    printf("Manger name = %s \n", managers[0].name);
    printf("Director name = %s \n", director.name);
    
    fclose(file);

    return 0;
}