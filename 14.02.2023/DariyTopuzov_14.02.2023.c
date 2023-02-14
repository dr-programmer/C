#include <stdio.h>

/*
int main()
{
    char string[100] = "Hello, World!";
    int count = 0;
    for(int i = 0; *(string + i) != '\0'; i++){
        count++;
    }
    printf("Count = %d \n", count);

    //char *p = string;
    //while(p++);
    //p - string -1;

    return 0;
}
*/

/*
void swap(void *a, void *b){
    int temp = *(int *)a;
    *(int *)a = *(int *)b;
    *(int *)b = temp;
}

int compareasc(void *pa, void *pb){
    if((*(int*)pa) > (*(int*)pb)){
        return 1;
    }
    else if((*(int*)pa) < (*(int*)pb)){
        return -1;
    }
    else return 0;
}

int comparedesc(void *pa, void *pb){
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
            if(compare((arr+j), (arr+j+1)) == 1){
                swap((arr+j), (arr+j+1));
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
    int arr[] = {1, 15, 100, 2, 0, 16};
    bubblesort(arr, 6, compareasc);
    printarray(arr, 6);

    return 0;
}
*/

/*
void strhalf(char *str, char **pp){
    int count = 0;
    for(int i = 0; *(str + i) != '\0'; i++){
        count++;
    }
    *pp = &str[count/2];
    //*pp = str + strlen(str) / 2;
}

int main()
{
    char str[] = "Hello, World!";
    char *p;
    strhalf(str, &p);
    printf("P = %s", p);

    return 0;
}
*/

#define ROWS 3
#define COLUMNS 4

void print2DArray(int (*arr)[COLUMNS], int rows){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < COLUMNS; j++){
            printf("%-3d", *(*(arr+i)+j));
        }
        printf("\n");
    }
}

int main()
{
    int arr[ROWS][COLUMNS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    print2DArray(arr, ROWS);

    return 0;
}