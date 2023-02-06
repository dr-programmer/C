#include <stdio.h>

int main()
{
    int arr[] = {1, 6, 3, 4, 2};
    
    printf("Size of int: %zu \n", sizeof(int));
    for(int i = 0; i < 5; i++){
        printf("arr[%d] = %p -> %d \n", i, &arr[i], arr[i]);
    }
    printf("arr = %p \n", arr);

    int *p = arr;
    //p + 1 if address of p == 10, => p + 1 == 14, because sizeof(int) == 4
    //p++;

    printf("&arr = %p \n", &arr);
    printf("p = %p \n", p);
    printf("&p = %p \n", &p);

    for(int i = 0; i < 5; i++){
        printf("p[%d] = %p -> %d \n", i, &p[i], p[i]);
        printf("p + %d = %p -> %d \n", i, p + i, *(p + i));
    }

    char str[] = "Ivan";
    for(char *p = str; *p != 0; p++){
        printf("%c", *p);
    }
    printf("\n");

    return 0;
}