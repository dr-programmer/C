#include "mystrings.h"

int strlength(char *arr){
    int i;
    for(i = 0; arr[i] != 0; i++);
    return i;
}

void strconcat(char *arr, char *arrs){
    int i;
    for(i = 0; arr[i] != 0; i++);
    for(int j = 0; arrs[j] != 0; j++){
        arr[i+j] = arrs[j];
        arr[i+j+1] = 0;
    }
}

int strcompare(char *arr1, char *arr2){
    for(int i = 0; arr1[i] != 0 || arr2[i] != 0; i++){
        if(arr1[i] < arr2[i])return -1;
        else if(arr1[i] > arr2[i])return 1;
    }
    return 0;
}