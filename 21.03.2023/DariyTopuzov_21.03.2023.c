#include <stdio.h>
#include <stdlib.h>
/*
typedef unsigned long long ull;

typedef ull (*F_PTR)(ull, ull);

ull add(ull x, ull y){
    return x + y;
}

ull reduce(ull *arr, ull arr_size, F_PTR function, ull starting_value){
    for(ull i = 0; i < arr_size; i++){
        starting_value = function(starting_value, arr[i]);
    }
    return starting_value;
}

int main()
{
    ull arr[] = {1, 2, 3};
    printf("%llu \n", reduce(arr, 3, add, 0));

    return 0;
}
*/
/*
typedef enum {
    SUNDAY,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY
} WeekDays;

int main()
{
    WeekDays day;
    printf("Please enter the number of the day: ");
    scanf("%d", &day);

    switch(--day) {
        case SUNDAY: printf("SUNDAY \n"); break;
        case MONDAY: printf("MONDAY \n"); break;
        case TUESDAY: printf("TUESDAY \n"); break;
        case WEDNESDAY: printf("WEDNESDAY \n"); break;
        case THURSDAY: printf("THURSDAY \n"); break;
        case FRIDAY: printf("FRIDAY \n"); break;
        case SATURDAY: printf("SATURDAY \n"); break;
        default: exit(0);
    }

    return 0;
}
*/
/*
typedef struct {
    char name[16];
    int number;
    double mark;
} Student;

int main()
{
    Student *class = NULL;
    int number = -1;
    while(1) {
        int choice;
        printf("1: Add a student, 2: Show all students, 3: exit \n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                number++;
                class = (Student *)realloc(class, (number+1) * sizeof(Student));
                if(class == NULL){
                    printf("Error allocating memory!");
                    exit(-1);
                }
                printf("Please enter the name of the student: \n");
                scanf("%s", &class[number].name);
                printf("Please enter the number of the student: \n");
                scanf("%d", &class[number].number);
                printf("Please enter the mark of the student: \n");
                scanf("%lf", &class[number].mark);
                break;
            case 2:
                for(int i = 0; i < (number + 1); i++){
                    printf("%-15s %-3d %-6.3lf \n", class[i].name, class[i].number, class[i].mark);
                }
                break;
            default:
                if(class != NULL)free(class);
                exit(-1);
        }
    }

    return 0;
}
*/

typedef union {
    long odd;
    short even;
} complex;

int main()
{
    complex carr[10];
    for(int i = 0; i < 9; i+=2){
        carr[i].even = i;
        carr[i+1].odd = i+1;
        printf("%ld ", carr[i+1]);
    }
    for(int i = 0; i < 10; i+=2){
        printf("%hu ", carr[i]);
    }

    return 0;
}