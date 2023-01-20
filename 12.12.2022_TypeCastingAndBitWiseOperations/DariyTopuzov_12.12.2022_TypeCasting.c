#include <stdio.h>
/* implicit
long double square(long double x){
    return x*x;
} 

int main()
{
    int a = 5;
    float a1 = a;
    printf("%f \n", a1);

    float b = 5.5;
    int b1 = b;
    printf("%d \n", b1);

    char c = -127;
    unsigned int c1 = c;
    printf("%u \n", c1);

    int d1 = 5;
    int d2 = 2;
    float d3 = d1 / d2;
    printf("%f \n", d3);

    float d4 = 2.0;
    float d5 = d1/d4;
    printf("%f \n", d5);

    long double result = square(d1);
    printf("%Lf \n", result);

    return 0;
}
*/

int main()
{
    int a = 5;
    float a1 = (float) a;
    printf("%f \n", a1);

    int b = -125;
    printf("%f \n", (double) b);

    int c = 5;
    int c1 = 2;
    float c2 = (float)c / (float)c1;
    printf("%f \n", c2);

    return 0;
}