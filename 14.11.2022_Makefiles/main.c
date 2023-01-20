#include <stdio.h>
#include "maths.h"
#include "strings.h"

int main()
{
    double result = square(5);
    printf("result = %lf \n", result);

    int len = stringlength("Ivan");
    printf("%d \n", len);

    return 0;
}