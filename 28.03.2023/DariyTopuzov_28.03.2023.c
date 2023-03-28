#include <stdio.h>

typedef struct {
    char firstName[20];
    char secondName[20];
    char thirdName[20];
    char email[20];
    int telNumber[10];
} Participant;

typedef enum {
    false,
    true
} Bool;

typedef struct {
    Participant participant;
    Bool WillGo;
} Comment;

typedef struct {
    int hours;
    int minutes;
} TimeOfDay;

typedef struct {
    char name[20];
    char description[100];
    struct {
        int day;
        int month;
        int year;
        TimeOfDay time;
    } date;
    Comment comments[100];
} Event;

int main()
{
    Participant someone = {"Adsa", "Sdsa", "Ddsa", "@dsa", 0};
    Comment first = {someone, true};
    Event event1 = {"Event1", "Very helpful!", {1, 1, 2024, {13, 0}}, {first}};
    Event event2 = {name: "Event2", description: "Very helpful!", date: {2, 2, 2024, {13, 0}}, comments: {first, {{"A", "S", "D", "@", 0}, true}}};

    return 0;
}