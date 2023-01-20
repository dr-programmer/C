#ifndef SCHOOL_ROOM
#define SCHOOL_ROOM

#include "person.h"

struct SchoolRoom{
    int number;
    struct Person humansHere[50];
};
#endif