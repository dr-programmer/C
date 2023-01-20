#include <stdio.h>

#include "quadraticroots.h"

int main()
{
    QuadraticRootsResult result;
    int a = 1, b = 3, c = 2;
    result = findroots(a, b, c);
    if(result.norealroots == 1)printf("No real roots. \n");
    else printf("x1 = %lf, x2 = %lf \n", result.x1, result.x2);

    float a1 = 1, b1 = 3, c1 = 2;
    result = findroots(a1, b1, c1);
    if(result.norealroots == 1)printf("No real roots. \n");
    else printf("x1 = %lf, x2 = %lf \n", result.x1, result.x2);

    double a2 = 1, b2 = 3, c2 = 2;
    result = findroots(a1, b1, c1);
    if(result.norealroots == 1)printf("No real roots. \n");
    else printf("x1 = %lf, x2 = %lf \n", result.x1, result.x2);

    return 0;
}