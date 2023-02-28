#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SLENGTH 17
#define RNROW(NAME, COUNT) char *tp; tp = strchr(NAME[COUNT], '\n'); if(tp != NULL)*tp = '\0';

int main()
{
    unsigned int count;
    do {
        printf("Enter the number of classes: ");
        scanf("%u", &count);
    } while(count <= 0);
    getchar();
    char **p = (char **)calloc(count, sizeof(char *));
    for(int i = 0; i < count; i++){
        printf("\n #%d class ", i+1);
        p[i] = (char *)calloc(SLENGTH, sizeof(char));
        fgets(p[i], SLENGTH - 1, stdin);
        RNROW(p, i)
    }
    char **names;
    unsigned int nstudents = 0;
    float **marks;
    while(1){
        unsigned int choice;
        printf("\n1: Add new student; 2: Show marks; 3: exit \n");
        scanf("%u", &choice);
        switch(choice){
            case 1: {
                getchar();
                printf("\n Write the name of the student: ");
                names = (char **)realloc(names, (nstudents + 1) * sizeof(char *));
                names[nstudents] = (char *)calloc(SLENGTH, sizeof(char *));
                fgets(names[nstudents], SLENGTH - 1, stdin);
                RNROW(names, nstudents)
                nstudents++;

                marks = (float **)realloc(marks, nstudents * sizeof(float *));
                marks[nstudents - 1] = (float *)calloc(count, sizeof(float));
                for(int j = 0; j < count; j++){
                    printf("\n Please enter the %s mark: ", p[j]);
                    scanf("%f", &marks[nstudents - 1][j]);
                }
                break;
            }
            case 2: {
                for(int i = 0; i < count; i++){
                    printf("%15s", p[i]);
                }
                for(int i = 0; i < nstudents; i++){
                    printf("\n%-15s", names[i]);
                    for(int j = 0; j < count; j++){
                        printf("%-15.2f", marks[i][j]);
                    }
                }
                break;
            }
            case 3: {
                for(int i = 0; i < count; i++){
                    if(p != NULL && p[i] != NULL)free(p[i]);
                }
                if(p != NULL)free(p);
                for(int i = 0; i < nstudents; i++){
                    if(names != NULL && names[i] != NULL)free(names[i]);
                    if(marks != NULL && marks[i] != NULL)free(marks[i]);
                }
                if(names != NULL)free(names);
                if(marks != NULL)free(marks);
                exit(0);
            }
        }
    }

    return 0;
}