#ifndef MACRO
#define MACRO

struct transformation{
    long result;
    char error[100];
};

struct transformation chartolong(char *string);
#endif