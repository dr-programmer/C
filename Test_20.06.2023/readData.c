#include <stdio.h>
#include <stdlib.h>

#include "participant.h"

int main()
{
    FILE *file = fopen("leaderboard.txt", "r");
    if(file == NULL) {
        printf("Cannot open file");
        exit(0);
    }

    Participant temp;
    while(fscanf(file, "%d %d ", &temp.number, &temp.time) > 0){
        fgets(temp.names, 100, file);
        printf("%d %d %s", temp.number, temp.time, temp.names);
    }

    fclose(file);

    return 0;
}