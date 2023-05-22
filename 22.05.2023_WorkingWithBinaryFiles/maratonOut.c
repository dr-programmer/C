#include <stdio.h>
#include <stdlib.h>

#include "participant.h"
#include "errors.h"

#define NUMBER_OF_PARTICIPANTS 3

int main()
{
    Participant participants[NUMBER_OF_PARTICIPANTS] = {
        {.number = 4, .time = 304, .firstname = "Ivan", .surname = "Ivanov"},
        {.number = 6, .time = 632, .firstname = "Dobromir", .surname = "Iliev"},
        {.number = 2, .time = 705, .firstname = "Nikolai", .surname = "Yordanov"}
    };
    
    FILE *file = fopen("maraton.bin", "wb");
    if(file == NULL) {
        printf("Cannot open file\n");
        exit(CANNOT_OPEN_FILE);
    }

    int participantsCount = NUMBER_OF_PARTICIPANTS;
    fwrite(&participantsCount, sizeof(int), 1, file);
    fwrite(participants, sizeof(Participant), participantsCount, file);

    fclose(file);

    return 0;
}