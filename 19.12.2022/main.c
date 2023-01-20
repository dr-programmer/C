#include "threads.h"

#include <stdio.h>

//extern int threadscount;

extern int test;
extern int newvar;

int foo(){
    return 10;
}

int main()
{
    createnewthread();
    createnewthread();

    printf("Threads count: %d \n", threadscount);
    //Undefined reference to test;
    //printf("%d \n", test);

    //Undefined reference to newvar
    //printf("%d \n", newvar);
    return 0;
}