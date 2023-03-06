#include <stdio.h>
/*
typedef const unsigned long long cull;

typedef int (*F_PTR)(int, int);

typedef int (*A_PTR)[3];

int main()
{
    const unsigned long long a;
    cull b;

    F_PTR ptr;

    int arr[] = {1, 2, 3};
    A_PTR aptr = &arr;
    printf("%d", aptr[0][0]);

    return 0;
}
*/

struct Student {
    char name[30];
    int grade;
    int number;
    float avggrade;
};

typedef struct Teacher {
    char name[30];
    int teachingInGrade;
} teacher;

void printStudent(char *name, int grade, int number, float avggrade){
    //Implementation
}

void printStudentBetter(struct Student student){
    printf("Name: %s \n", student.name);
    printf("Grade: %d \n", student.grade);
}

int main()
{
    teacher teacher1;

    return 0;
}