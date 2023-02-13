#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr = (int *)malloc(5 * sizeof(int));
    arr[0] = 5;
    arr[1] = 7;
    arr[2] = 10;
    arr[3] = 15;
    arr[4] = 14;

    for(int i = 0; i < 5; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);

    int *p = (int *)malloc(sizeof(int));
    *p = 7;
    printf("%d \n", *p);

    free(p);

    int *a = (int *)calloc(3, sizeof(int));

    a[0] = 1;
    a[1] = 3;
    a[2] = 5;

    a = (int *)realloc(a, 4 * sizeof(int));
    a[3] = 10;

    a = (int *)realloc(a, 2 * sizeof(int));

    return 0;
}