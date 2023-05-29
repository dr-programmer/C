#include <stdio.h>
#include <stdlib.h>

#include "fileUtil.h"
#include "linkedlist.h"

int main(int argc, char **argv)
{
    Patient patients[] = {
        {.name = "Hi0", .EGN = 111222333, .age = 37, .symptoms = "Headache"},
        {.name = "Hi1", .EGN = 111222333, .age = 37, .symptoms = "Headache"},
        {.name = "Hi2", .EGN = 111222333, .age = 37, .symptoms = "Headache"},
    };

    char *filename = argv[1];
    FILE *outputFile = fopen(filename, "w");
    ASSERT_FILE_OPEN(outputFile);

    for (int i = 0; i < 3; i++) {
        fprintf(outputFile, "%s,%ld,%d,%s\n", patients[i].name, patients[i].EGN, patients[i].age, patients[i].symptoms);
    }

    fclose(outputFile);

    return 0;
}