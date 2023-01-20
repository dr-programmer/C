#include <stdio.h>
#include "mystrings.h"

int main(int argc, char **argv)
{
    if(argc == 1){
        printf("Enter a string!\n");
        return 0;
    }
    printf("%d \n", strlength(argv[1]));
    return 0;
}