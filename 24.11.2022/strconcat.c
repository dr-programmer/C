#include <stdio.h>
#include "mystrings.h"

int main(int argc, char **argv)
{
    if(argc < 3){
        printf("Enter at least 2 strings!\n");
        return 0;
    }
    if(strlength(argv[1]) > 50 || strlength(argv[2]) > 50){
        printf("The maximum length of the strings must be 50!\n");
        return 0;
    }
    char string[101];
    for(int i = 0; argv[1][i] != '\0'; i++){
        string[i] = argv[1][i];
    }
    strconcat(string, argv[2]);
    printf("%s \n", string);
    return 0;
}