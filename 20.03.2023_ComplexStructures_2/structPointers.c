#include <stdio.h>

typedef struct {
    char name[30];
    int number;
} Student;

int main()
{
    Student ivan = {name: "Ivan", number: 5};
    Student student2 = ivan;

    Student *student = &ivan;
    printf("%d \n", (*student).number);
    printf("%d \n", student->number);

    return 0;
}