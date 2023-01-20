#include <stdio.h>
#include "mystrings.h"

int main(int argc, char **argv)
{
    if(argc < 3){
        printf("Enter at least 2 strings!\n");
        return 0;
    }
    printf("%d \n", strcompare(argv[1], argv[2]));
    return 0;
}