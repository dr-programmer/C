#include <stdio.h>

int a = 7;

int foo(void){
    a++;
    printf("In Foo: %d \n", a);
}

int main()
{
    foo();
    printf("In Main: %d \n", a);

    return 0;
}