#include <stdio.h>
/*
#define DEBUG

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int sum = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = arr[j];
            }
        }
    }
    for(int i = 0; i < 5; i++){
        #ifdef DEBUG
        printf("%d\n", arr[i]);
        #endif
        if(i % 3 == 0){
            sum += arr[i];
            #ifdef DEBUG
            printf("Devidable by 3: %d\n", arr[i]);
            #endif
        }
    }
    return 0;
}
*/
/*
#define ARRAY_SIZE 5

int main()
{
    #if defined ARRAY_SIZE && ARRAY_SIZE > 0 && ARRAY_SIZE < 10
    double arr[ARRAY_SIZE];
    for(int i = 0; i < ARRAY_SIZE; i++){
        int stepen = 1;
        for(int j = 0; j < i; j++){
            stepen *= 2;
        }
        arr[i] = stepen;
        printf("%lf \n", arr[i]);
    }
    #else
    printf("Please insert a valid value in ARRAY_SIZE or define it.");
    #endif
    return 0;
}
*/
#define ARRAY_SIZE 5
int main()
{
    int arr[ARRAY_SIZE] = {1, 2, 3, 4, 5};
    #ifdef _WIN32
    for(int i = 0; i < ARRAY_SIZE-1; i++){
        for(int j = 0; j < ARRAY_SIZE-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = arr[j];
            }
        }
    }
    #elif defined __linux__
    for(int i = 0; i < ARRAY_SIZE-1; i++){
        int min = i;
        for(int j = i+1; j < ARRAY_SIZE; j++){
            if(arr[min] > arr[j]){
                int temp = arr[min];
                arr[min] = arr[j];
                arr[j] = arr[min];
            }
        }
    }
    #elif defined __APPLE__
    int key, j;
    for (int i = 1; i < ARRAY_SIZE; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    #else
    for(int i = 0; i < ARRAY_SIZE/2; i++){
        int temp = arr[i];
        arr[i] = arr[ARRAY_SIZE-1-i];
        arr[ARRAY_SIZE-1-i] = temp;
    }
    #endif
    return 0;
}

