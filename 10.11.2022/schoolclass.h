#ifndef SCHOOL_CLASS
#define SCHOOL_CLASS
#include "person.h"

struct SchoolClass{
    struct Person students[26];
    char clasletter;
    int number;
    struct Person teacher;
};
#endif