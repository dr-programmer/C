#include <stdio.h>
#include <stdlib.h>

int main()
{
    int count = 0;
    do{
        printf("Please enter the number of grades: ");
        scanf("%d", &count);
    } while(count <= 0);
    float *grades = (float *)calloc(count, sizeof(float));
    if(grades == NULL){
        printf("Error allocating memory!");
        return -1;
    }
    for(int i = 0; i < count; i++){
        do{
            printf("\n Grade #%d: ", i+1);
            scanf("%f", grades + i);
        } while(grades[i] > 6 || grades[i] < 2);
    }
    while(1){
        int choice;
        printf("1: Print average mark; 2: New grade; 3: Delete last grade; 4: Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1: {
                float avg = 0;
                for(int i = 0; i < count; i++){
                    avg += grades[i];
                }
                if(count != 0)avg /= count;
                else avg = 0;
                printf("Average mark: %f \n", avg);
                break;
            }
            case 2: {
                int new = 0;
                do{
                    printf("Please enter the number of new grades: ");
                    scanf("%d", &new);
                } while(new <= 0);
                count += new;
                grades = (float *)realloc(grades, count * sizeof(float));
                if(grades == NULL){
                    printf("Error allocating memory!");
                    return -1;
                }
                for(int i = count - new; i < count; i++){
                    do{
                        printf("\n Grade #%d: ", i+1);
                        scanf("%f", grades + i);
                    } while(grades[i] > 6 || grades[i] < 2);
                }
                break;
            }
            case 3: {
                if(count >= 1)count--;
                if(count != 0)grades = (float *)realloc(grades, count * sizeof(float));
                else {
                    if(grades != NULL){
                        free(grades);
                    }
                    grades = (float *)realloc(NULL, count * sizeof(float));
                }
                if(grades == NULL){
                    printf("Error allocating memory!");
                    return -1;
                }
                break;
            }
            case 4: {
                if(grades != NULL){
                    free(grades);
                }
                exit(0);
            }
        }
    }


    return 0;
}