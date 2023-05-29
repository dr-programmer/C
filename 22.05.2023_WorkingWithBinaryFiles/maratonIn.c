#include <stdio.h>
#include <stdlib.h>

#include "participant.h"
#include "errors.h"

int main()
{
    FILE *file = fopen("maraton.bin", "rb");
    if(file == NULL) {
        printf("Cannot open file\n");
        exit(CANNOT_OPEN_FILE);
    }

    int participantsCount = 0;
    fread(&participantsCount, sizeof(int), 1, file);

    Participant *participants = (Participant *)calloc(participantsCount, sizeof(Participant));
    //Participant participants[3];
    fread(participants, sizeof(Participant), participantsCount, file);
    printParticipants(participants, participantsCount);

    free(participants);
    fclose(file);

    return 0;
}