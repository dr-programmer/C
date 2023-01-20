#include<stdio.h>
#define ARRAY_SIZE 8
#define NUMBERS 1, 2, 3, \
                            4, 5, 6, 7, 8
/*
int main()
{
    const int arraysize = 8;
    int arr[ARRAY_SIZE] = {NUMBERS};
    for(int i = 0; i < ARRAY_SIZE; i++){
        printf("%d \n", arr[i]);
    }
    return 0;
}
*/

#define ONE main(){
#define TWO printf("Hi! \n");
#define THREE return 0;
#define END }
/*
ONE
TWO
THREE
END
*/

#define SIMPLE_PRINT(MESSAGE) printf(MESSAGE)
#define OBJECT_PRINT printf("Hello, World \n")
/*
int main()
{
    OBJECT_PRINT;
    SIMPLE_PRINT("Hello, World");
    //printf(MESSAGE) => printf("Hello, World")
    return 0;
}
*/

#define DEBUG(VALUE, FORMAT) printf("The value of " #VALUE " is: " FORMAT, VALUE)
/*
int main()
{
    int somevar = 7;
    DEBUG(somevar, "%d \n");

    printf("Hello " "World \n");
    return 0;
}
*/

/*
void print_command() {
    printf("The program is printing \n");
}

void quit_command() {
    printf("The program is exiting \n");
}

#define CALL_COMMAND(COMMAND) COMMAND ## _command()

int main()
{
    CALL_COMMAND(print);
    CALL_COMMAND(quit);
    return 0;
}
*/

#define SQUARE(X) X*X
#define SAFE_SQUARE(X) (X) * (X)
/*
int main()
{
    printf("%d \n", SQUARE(2)); // 2 * 2
    printf("%d \n", SQUARE(2+1)); // 2 + 1 * 2 + 1

    printf("%d \n", SAFE_SQUARE(2)); // (2) * (2)
    printf("%d \n", SAFE_SQUARE(2+1)); // (2 + 1) * (2 + 1)
    return 0;
}
*/

// __FILE__
// __LINE__
// __DATE__
// __TIME__

int main()
{
    printf("The %s has error on line %d \n", __FILE__, __LINE__);
    return 0;
}