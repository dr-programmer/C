#include <stdio.h>

#include "safeint.h"

int main(int argc, char **argv)
{
    struct SafeResult result;
    int a, b;
    a = safestrtoint(argv[1]).value;
    b = safestrtoint(argv[2]).value;
    result = safeadd(a, b);
    if(result.errorflag == 1){
        printf("Error");
    }
    else {
        printf("Result = %d", result.value);
    }
    return 0;
}