#include <stdio.h>
/*
#define ARRAY int arr[5] = {1, 2, 3, 4, 5}
#define PRINT_ARRAY for(int i = 0; i < 5; i++){printf("%d \n", arr[i]);}

int main()
{
    ARRAY;
    PRINT_ARRAY;
    return 0;
}
*/
/*
#define COMPARE(VALUE1, VALUE2) int temp = VALUE1 > VALUE2 ? VALUE1 : VALUE2

int main()
{
    COMPARE(6, 3);
    printf("%d \n", temp);
    return 0;
}
*/
/*
#define MY_DEBUG(VAR, TYPE) printf("\n " #VAR " has a value " TYPE " and is in " __FILE__ " line %d. \n", VAR, __LINE__)

int main()
{
    int a = 5;
    MY_DEBUG(a, "%d");
    return 0;
}
*/
/*
#define COMMAND(NAME, TYPE) TYPE ## _ ## NAME ## _command
#define DEFINE_COMMAND(NAME, TYPE) void COMMAND(NAME, TYPE)(void)
#define DEFINE_EXTERNAL_COMMAND(NAME) DEFINE_COMMAND(NAME, external)
#define DEFINE_INTERNAL_COMMAND(NAME) DEFINE_COMMAND(NAME, internal)
#define CALL_COMMAND(NAME, TYPE) COMMAND(NAME, TYPE)()
#define CALL_INTERNAL_COMMAND(NAME) CALL_COMMAND(NAME, internal)
#define CALL_EXTERNAL_COMMAND(NAME) CALL_COMMAND(NAME, external)

DEFINE_COMMAND(quit, external){
    printf("\n hELLO");
}

int main()
{
    return 0;
}
*/
/*
#define SWAP(A, B, TYPE) TYPE temp = A; A = B; B = temp;

int main()
{
    int a = 3, b = 5;
    SWAP(a, b, int);
    printf("a = %d, b = %d \n", a, b);
    return 0;
}
*/
#define SWAP(A, B, TYPE) TYPE temp = A; A = B; B = temp;
#define SORT(ARRAY, SIZE, TYPE, COMPARE) for(int i = 0; i < SIZE-1; i++){\
                                            for(int j = 0; j < SIZE-1; j++){\
                                                if(ARRAY[j] COMPARE ARRAY[j+1]){\
                                                    SWAP(ARRAY[j], ARRAY[j+1], TYPE)\
                                                }\
                                            }\
                                        }

int main()
{
    int arr[5] = {1, 4, 2, 6, 2};
    SORT(arr, 5, int, >);
    for(int i = 0; i < 5; i++){
        printf("%d \n", arr[i]);
    }
    return 0;
}