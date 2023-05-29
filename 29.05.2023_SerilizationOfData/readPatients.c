#include <stdio.h>
#include <string.h>

#include "linkedlist.h"
#include "fileUtil.h"

#define MAX_LINE_LENGTH 6000

int main(int argc, char **argv)
{
    char *filename = argv[1];
    FILE *outputFile = fopen(filename, "r");
    ASSERT_FILE_OPEN(outputFile);

    char line[MAX_LINE_LENGTH];
    while(fgets(line, MAX_LINE_LENGTH, outputFile) != NULL) {
        char *token = strtok(line, ",");
        while(token != NULL) {
            printf("%s \n", token);
            token = strtok(NULL, ",");
            //Create patient form the tokens
            //Add to the linked list
        }
    }

    fclose(outputFile);

    return 0;
}