#include <stdio.h>
#include <stdlib.h>
/*
int *foo() {
    int arr[3] = {1, 2, 3};

    return arr;
}
*/

int *foo2() {
    int *arr = (int *)calloc(3, sizeof(int));
    arr[0] = 4;
    arr[1] = 5;
    arr[2] = 6;

    return arr;
}

int main()
{
    //int *p = foo();
    //printf("%d ", p[0]); -> segmentation fault

    int *p2 = foo2();
    printf("%d ", p2[0]);
    free(p2);

    return 0;
}