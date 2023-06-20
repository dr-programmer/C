#include <stdio.h>
#include <stdlib.h>

#include "participant.h"

int main()
{
    Participant arr[3] = {
        {.number = 1, .time = 10, .names = "Pesho T Vilev"},
        {.number = 2, .time = 12, .names = "Ivan K Todorov"},
        {.number = 3, .time = 14, .names = "Gogo P Georgiev"}
    };

    FILE *file = fopen("leaderboard.txt", "w");
    if(file == NULL) {
        printf("Cannot open file \n");
        exit(0);
    }

    for(int i = 0; i < 3; i++) {
        fprintf(file, "%d %d %s \n", arr[i].number, arr[i].time, arr[i].names);
    }

    fclose(file);

    return 0;
}