#include <stdio.h>
#include "transformation.h"

int main()
{
    char string[100] = "-123";
    struct transformation rt = chartolong(string);
    printf("result = %ld, eroor = %s", rt.result, rt.error);
    return 0;
}