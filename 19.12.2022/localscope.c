#include <stdio.h>

int main()
{
    int a = 5;
    printf("%d \n", a);

    {
        //Shadowing - a shadows a
        int a = 7;
        printf("%d \n", a);
    }
    
    {
        int c = 10;
    }

    return 0;
}