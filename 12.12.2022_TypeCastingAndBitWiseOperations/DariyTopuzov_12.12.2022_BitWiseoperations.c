#include <stdio.h>

int main()
{
    //0000 0110
    char a = 6;

    //0000 0111
    char b = 7;

    //0000 0110
    //0000 0111
    //0000 0110
    char c = a & b;
    printf("%d \n", c);

    //0000 0110
    //0000 0111
    //0000 0111
    char d = a | b;
    printf("%d \n", d);

    //0000 0110
    //1111 1001
    unsigned char e = ~a;
    printf("%u \n", e);

    //0000 0110 - a
    //0000 0111 - b
    //0000 0001 - XOR - a ^ b
    unsigned char f = a ^ b;
    printf("%u \n", f);

    //0000 0001 - g
    //g << 2 - 0000 0100
    char g = 1;
    printf("%d \n", g << 2);

    //0000 0001 - h
    // h >> 2 - 0000 0000
    char h = 1;
    printf("%d \n", h >> 2);


    //2^n
    char n = 10;
    int i = 1 << n;
    printf("%d \n", i);

    return 0;
}