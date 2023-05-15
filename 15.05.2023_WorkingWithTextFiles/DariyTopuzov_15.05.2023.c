#include <stdio.h>
#include <stdlib.h>
/*
int main()
{
    FILE * textFile = fopen("test.txt", "w");
    if(textFile == NULL) {
        printf("Cannot open the file \n");
        exit(0);
    }

    //Using the file
    //fprintf
    //fputs
    //fputc
    fprintf(textFile, "%s %d %lf\n", "Ivan", 1, 5.5);
    fputs("Nikolai\n", textFile);
    fputc('a', textFile);

    fclose(textFile);

    return 0;
}
*/

int main()
{
    FILE *textFile = fopen("test.txt", "r");
    if(textFile == NULL) {
        printf("Cannot open the file \n");
        exit(0);
    }

    //Reading from file
    //fscanf
    //fgets
    //fgetc
    char name[40];
    int number;
    double average;
    fscanf(textFile, "%s %d %lf\n", name, &number, &average);
    printf("Name: %s, number: %d, average grade: %.2lf \n", name, number, average);

    char line[100];
    fgets(line, 100, textFile);
    printf("Line %s", line);

    char symbol = fgetc(textFile);
    printf("Symbol %c\n", symbol);

    fclose(textFile);

    return 0;
}