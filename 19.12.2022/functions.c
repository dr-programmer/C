#include <stdio.h>

#define SIZE 3

void foo(int a){
    a++;
    printf("In Foo: %d \n", a);
}
/*
int * test(){
    int arr[SIZE] = {1,2,3};
    return arr;
}
*/

int * test2(int * arr, int size){
    for(int i = 0; i < size; i++){
        arr[i] = i+1;
    }
    return arr;
}

int main()
{
    int a = 7;
    foo(a);
    printf("In Main: %d \n", a);

    /*
    Segmentation fault
    int * result1 = test();
    for(int i = 0; i < SIZE; i++){
        printf("%d \n", result1[i]);
    }
    */

    int myarr[SIZE] = {1,2,3};
    int * result2 = test2(myarr, SIZE);
    for(int i = 0; i < SIZE; i++){
        printf("%d \n", myarr[i]);
    }
    return 0;
}