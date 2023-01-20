#include <stdio.h>
/*
#define WINDOWS 0
#define LINUX 1

void printosinfo(){
    printf("This is os info: ");

    #ifdef WINDOWS
    printf("We are under Windows");
    #endif

    #ifndef LINUX
    printf("We are under Linux");
    #endif

    #if LINUX == 1
    printf("We are under Linux");
    #endif
}

int main()
{
    printosinfo();
    return 0;
}
*/

/*
#define SOME
#define HELLO

int main()
{
    #if defined SOME
    printf("Some \n");
    #endif

    #if !defined SOME
    printf("Not some \n");
    #endif

    #if defined SOME && define HELLO
    printf("Some hello \n");
    #endif
}
*/

/*
#define LINUX 1

//__linux__ - defined if under Linux
//_WIN32 - defined if under Windows 32 or Windows 64
//__APPLE__ - defined if under MacOS

int main()
{
    #if defined LINUX
    printf("Linux \n");
    #else
    printf("Else \n");
    #endif

    #ifdef __linux__
    printf("Under Linux \n");
    #endif
    #ifdef _WIN32
    printf("Under Windows \n");
    #endif
    #ifdef __APPLE__
    printf("Under MacOS");
    #endif
}
*/

/*
#define LINUX

int main()
{
    #if defined _WIN32
    printf("Windows");
    #elif defined __linux__
    printf("Linux");
    #else
    printf("MacOS");
    #endif
}
*/

#include <string.h>
#include "osinfo.h"

int main()
{
    struct osinfo os;
    strcpy(os.name, "Linux");
    puts(os.name);
    return 0;
}

int add(int a, int b){
    return a+b;
}

