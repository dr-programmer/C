#include <stdio.h>

typedef struct {
    char name[30];
    int number;
} Student;

typedef struct {
    int grade;
    char classname;
    Student students[26];
} StudentClass;

typedef struct {
    struct {
        char name[30];
        char teachersubject[30];
    } teacher;
    StudentClass studentClass;
    float startingtime;
    int duration;
} Activity;

typedef struct {
    Activity activities[8];
    enum {
        SUNDAY,
        MONDAY,
        TUESDAY,
        WEDNESDAY,
        THURSDAY,
        FRIDAY,
        SATURDAY
    } day;
} DaySchedule;

int main()
{
    

    return 0;
}