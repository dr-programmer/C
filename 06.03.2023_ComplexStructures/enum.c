#include <stdio.h>

enum weekday {
    SUNDAY,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY
};

enum month {
    JAN = 2,
    FEB, //Will have a value of 3
    MAR = 7,
    APR,
    MAY,
    JUN,
    JUL,
    AUG = 15,
    SEP = 17,
    OCT = 5,
    NOV,
    DEC //Will have the same value as MAR
};

typedef enum Bool {
    true = 1,
    false = 0
} bool;

int main()
{
    enum weekday day = SUNDAY;
    day = MONDAY;
    //day = JAN; //Not a good practise

    switch (day) {
        case SATURDAY:
        case SUNDAY:
            printf("Time to relax!");
            break;
        default:
            printf("Time for school\n");
            break;
    }

    printf("SUNDAY: %d\n", SUNDAY);
    printf("WEDNESDAY: %d\n", WEDNESDAY);
    printf("CURRENT DAY: %d\n", day);

    printf("December: %d\n", DEC);
    printf("March: %d\n", MAR);

    enum month currentmonth = MAR;

    enum Bool isSunny = true;
    if (isSunny){
        printf("It is a good day for a walk outside \n");
    }
    else {
        printf("Better to read a book \n");
    }

    bool isRainy = false;

    return 0;
}