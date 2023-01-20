#include<stdio.h>

int main()
{
    //0000 0000
    char rooms = 0;

    char room1 = 1 << 0;
    char room2 = 1 << 1;
    char room3 = 1 << 2;
    char room4 = 1 << 3;
    char room5 = 1 << 4;
    char room6 = 1 << 5;
    char room7 = 1 << 6;
    char room8 = 1 << 7;

    //Turn the light in room4
    rooms = rooms | room4;

    //Check whether the light is turned on in room4
    room4 == rooms & room4;

    return 0;
}