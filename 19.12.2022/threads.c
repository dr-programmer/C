#include "threads.h"

int threadscount = 0;

//Only visible in this file
static int newvar = 7;

int createnewthread(){
    threadscount++;

    return threadscount;
}

static int foo(){
    return 5;
}