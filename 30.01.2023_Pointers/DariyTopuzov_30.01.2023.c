#include <stdio.h>
/*
int main()
{
    int a = 10;
    printf("%p\n", &a);

    int *p = &a;
    printf("%p\n", p);
    printf("%p\n", &p);

    printf("%d\n", *p);
    *p = 15;
    printf("%d\n", a);

    int x1 = 12;
    int x2 = 15;

    int *k = &x1;
    int *z = k;

    printf("%d\n", *z);
    printf("%d\n", *k);

    *z = 21;

    printf("%d\n", *z);
    printf("%d\n", *k);
    printf("%d\n", x1);

    float b1 = 5.5;
    float *l2 = &b1;

    //sizeof(l2) = 4 - 32 bit / 8 - 64 bit

    return 0;
}
*/
/*
int main()
{
    int a = 10;
    float b = 5.5;

    void *p = &a;
    *(int *)p = 25;
    printf("%d\n", *(int*)p);

    p = &b;
    *(float *)p = 7.5;
    //*(int *)p = 15;
    //0000 0000 0000 0000 00000 0000 1111
    printf("%f\n", *(float*)p);

    return 0;
}
*/
/*
void print(int x){
    printf("%d\n", x);
}
typedef void (* fptype) (int);
int main()
{
    void (* fpointer)(int) = print;
    (*fpointer)(10);

    fptype asd = print;
    asd(5);

    return 0;
}
*/

void setxtofive(int* x){
    *x = 5;
}

void swap(int *x1, int *x2){
    int temp;
    temp = *x1;
    *x1 = *x2;
    *x2 = temp;
}

int main()
{
    int a = 15;
    setxtofive(&a);
    printf("%d\n", a);

    int x1 = 10;
    int x2 = 15;
    swap(&x1, &x2);
    printf("%d\n", x1);
    printf("%d\n", x2);

    return 0;
}
