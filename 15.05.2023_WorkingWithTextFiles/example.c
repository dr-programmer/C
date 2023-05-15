#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *textFile = fopen("records.txt", "r");
    if(textFile == NULL) {
        printf("Cannot open the file \n");
        exit(0);
    }

    char name[40];
    int number;
    double average;

    while(fscanf(textFile, "%s %d %lf\n", name, &number, &average) > 0) {
        printf("Name: %s, number: %d, average mark: %lf \n", name, number, average);
    }

    fclose(textFile);

    FILE *textFile1 = fopen("records.txt", "r");
    if(textFile1 == NULL) {
        printf("Cannot open the file \n");
        exit(0);
    }

    char line[100];
    while(fgets(line, 100, textFile1) != NULL) {
        printf("Line: %s", line);
    }

    fclose(textFile);

    return 0;
}