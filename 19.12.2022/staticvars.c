#include <stdio.h>

int initialize(){
    return 50;
}

void countcall(){
    static int count = 0;
    count++;
    printf("%d \n", count);

    //Must be DEFINED with a constant
    //static int test = initialize(); - error
}

int main()
{
    countcall();
    countcall();
    countcall();
    return 0;
}