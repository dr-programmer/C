#include <stdio.h>
/*
int main()
{
    char b = 'a';
    printf("%c \n", b);
    unsigned char b1 = 'a';

    short f = 5;
    printf("%hd \n", f);
    unsigned short f1 = 5;
    printf("%hu \n", f1);

    int a = 5;
    printf("%d \n", a);
    unsigned int a1 = 5;
    printf("%u ", a1);

    long e = 5;
    printf("%ld \n", e);
    unsigned long e1 = 5;
    printf("%lu \n", e1);

    long long g = 5328910389132;
    printf("%lld \n", g);
    unsigned long long g1 = 123218390324890;
    printf("%llu \n", g1);

    float c = 5.5;
    printf("%f \n", c);
    
    double d = 5.85;
    printf("%lf \n", d);

    long double h = 5.8512342;
    printf("%Lf \n", h);

    return 0;
}
*/
/*
int main()
{
    //6 - 0000 0110
    char a = 6;

    //one's complement - обратен код 0 - 255 (-126 - 0, 0 - 126)
    // 0000 0110 - binary (6)
    // 1111 1001 - 1's complement (-6)

    //two's complement - допълнителен код = 1's complement + 1
    // 0000 0110 - binary (6)
    // 1111 1001 - 1's complement
    // 1111 1010 - 2's complement (-6)

    //sign magnitute representation - прав код
    //0000 0110 - binary (6)
    //1000 0110 - SMR (-6)

    return 0;
}
*/
/*
#include <limits.h>

int main()
{

    printf("MIN: %hd \n", SHRT_MIN);
    printf("MAX: %hd \n", SHRT_MAX);
    printf("UNSIGNED MAX: %hu \n", USHRT_MAX);

    short a = SHRT_MIN;
    a--;
    printf("A: %hd \n", a);

    short b = SHRT_MAX;
    b++;
    printf("B: %hd \n", b);

    return 0;
}
*/
/*
int main()
{
    int b = 5;
    size_t size = sizeof(b);
    printf("Size of b = %zu \n", size);
    printf("Size of b = %zu \n", sizeof(b));
    printf("Size of long = %zu \n", sizeof(long));
}
*/
/*
int main()
{
    int a = 5;
    printf("Address of a: %p \n", &a);

    int b[3] = {1, 2, 3};
    printf("1: %p \n", &b[0]);
    printf("2: %p \n", &b[1]);
    printf("3: %p \n", &b[2]);
}
*/

struct test
{
    char a;
    char b;
    int c;
};


int main()
{
    long a[3] = {1, 2, 3};
    printf("Size of array: %zu \n", sizeof(a));

    //Doesn't work in functions
    size_t length = sizeof(a) / sizeof(a[0]);
    printf("Length of array: %zu \n", length);

    printf("Size of struct: %zu \n", sizeof(struct test));
}