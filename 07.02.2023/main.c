#include <stdio.h>
#include <string.h>
/*
int main()
{
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);

    int *pa;
    int *pb;
    pa = &a;
    pb = &b;
    printf("&a = %p -> %d, &b = %p -> %d \n", pa, *pa, pb, *pb);

    char string[100];
    fgets(string, 99, stdin);
    char *pc;
    pc = strchr(string, '\n');
    if(pc != NULL)*pc = '\0';
    return 0;
}
*/

int compareasc(void *pa, void *pb){
    /*
    int result = *(int*)pa > *(int*)pb ? 1 : -1;
    result = *(int*)pa == *(int*)pb ? 0 : result;
    return result;
    */
    if((*(int*)pa) > (*(int*)pb)){
        return 1;
    }
    else if((*(int*)pa) < (*(int*)pb)){
        return -1;
    }
    else return 0;
}

int comparedesc(void *pa, void *pb){
    /*
    int result = *(int*)pa < *(int*)pb ? 1 : -1;
    result = *(int*)pa == *(int*)pb ? 0 : result;
    return result;
    */
    if((*(int*)pa) > (*(int*)pb)){
        return -1;
    }
    else if((*(int*)pa) < (*(int*)pb)){
        return 1;
    }
    else return 0;
}

void bubblesort(int *arr, int count, int(* compare)(void *, void *)){
    for(int i = 0; i < count - 1; i++){
        for(int j = 0; j < count - 1; j++){
            if(compare(&arr[j], &arr[j+1]) == 1){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void printarray(int *arr, int count){
    for(int i = 0; i < count; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int x1 = 1, x2 = 3;
    int a = compareasc(&x1, &x2);
    int b = comparedesc(&x1, &x2);

    printf("a = %d, b = %d \n", a, b);

    int arr[7] = {5, 2, 6, 1, 10, 23, 1};
    bubblesort(arr, 7, compareasc);
    printarray(arr, 7);

    bubblesort(arr, 7, comparedesc);
    printarray(arr, 7);

    return 0;
}