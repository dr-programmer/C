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

    struct Employee manager0 = {.name = "Manager1", .numberOfWorkers = 3, .workers = &workers0};
    struct Employee manager1 = {.name = "Manager2", .numberOfWorkers = 3, .workers = &workers1};
    struct Employee managers[] = {manager0, manager1};

    struct Employee director = {.name = "TheDirector", .numberOfWorkers = 2, .workers = &managers};

    FILE *file = fopen("file.bin", "wb");
    if(file == NULL) {
        printf("Cannot open file");
        exit(0);
    }
    int numbOfworkers = 3, stop = 0;
    fwrite(&numbOfworkers, sizeof(int), 1, file);
    for(int i = 0; i < numbOfworkers; i++) {
        fwrite(&workers0[i].name, sizeof(char), 100, file);
    }

    fwrite(&manager0.name, sizeof(char), 100, file);

    fwrite(&numbOfworkers, sizeof(int), 1, file);
    for(int i = 0; i < numbOfworkers; i++) {
        fwrite(&workers1[i].name, sizeof(char), 100, file);
    }

    fwrite(&manager1.name, sizeof(char), 100, file);

    fwrite(&stop, sizeof(int), 1, file);
    fwrite(&director.name, sizeof(char), 100, file);

    fclose(file);

    return 0;
}