#include <stdio.h>
#include <stdlib.h>

int main()
{
    int markscount = 0;
    printf("Please enter the number of marks: ");
    scanf("%d", &markscount);

    //float *marks = (float *)malloc(markscount * sizeof(float));
    float *marks = (float *)calloc(markscount, sizeof(float));
    if(marks == NULL){
        printf("Error allocating memory");
        return 1;
    }

    for (int i = 0; i < markscount; i++)
    {
        printf("Mark %d: ", i+1);
        scanf("%f", (marks + i));
    }
    float sum = 0;
    for (int i = 0; i < markscount; i++)
    {
        sum += marks[i];
    }
    if(marks != NULL){
        free(marks);
    }

    printf("Avg = %f \n", (sum / markscount));
    
    int *p = (int *)malloc(sizeof(int));
    *p = 7;
    printf("%d \n", *p);

    free(p);

    return 0;
}