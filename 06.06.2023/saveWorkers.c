#include <stdio.h>
#include <stdlib.h>

#include "structures.h"

int main()
{
    struct Employee worker0 = {.name = "Pesho", .numberOfWorkers = 0, .workers = NULL};
    struct Employee worker1 = {.name = "Ivan", .numberOfWorkers = 0, .workers = NULL};
    struct Employee worker2 = {.name = "Niki", .numberOfWorkers = 0, .workers = NULL};
    struct Employee worker3 = {.name = "Gosho", .numberOfWorkers = 0, .workers = NULL};
    struct Employee worker4 = {.name = "Penka", .numberOfWorkers = 0, .workers = NULL};
    struct Employee worker5 = {.name = "Zanzibar", .numberOfWorkers = 0, .workers = NULL};
    struct Employee workers0[] = {worker0, worker1, worker2};
    struct Employee workers1[] = {worker3, worker4, worker5};

    struct Employee *pwork0 = workers0;
    struct Employee *pwork1 = workers1;

    struct Employee manager0 = {.name = "Manager1", .numberOfWorkers = 3, .workers = &pwork0};
    struct Employee manager1 = {.name = "Manager2", .numberOfWorkers = 3, .workers = &pwork1};
    struct Employee managers[] = {manager0, manager1};

    struct Employee *pman = managers;

    struct Employee director = {.name = "TheDirector", .numberOfWorkers = 2, .workers = &pman};

    FILE *file = fopen("file.bin", "wb");
    if(file == NULL) {
        printf("Cannot open file");
        exit(0);
    }
    
    int stop = 0;
    for(int i = 0; i < director.numberOfWorkers; i++) {
        fwrite(&(director.workers[0]+i)->numberOfWorkers, sizeof(int), 1, file);
        struct Employee *temp = (director.workers[0]+i)->workers[0];
        for(int j = 0; j < (director.workers[0]+i)->numberOfWorkers; j++) {
            fwrite(&(temp+j)->name, sizeof(char), 100, file);
        }
        fwrite(&(director.workers[0]+i)->name, sizeof(char), 100, file);
    }
    fwrite(&stop, sizeof(int), 1, file);
    fwrite(&director.name, sizeof(char), 100, file);

    fclose(file);

    return 0;
}