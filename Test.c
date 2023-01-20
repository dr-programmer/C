#include<stdio.h>
/*
int main()
{
    int n = 3, fact = 1;
    for(int i = 2; i < n+1; i++){
        fact = fact*i;
    }
    printf("%d \n", fact);
    return 0;
}
*/
int main()
{
    int arr[] = {1, 5, 2, 8, 10, 2, 123, 0};
    for(int i = 1; i < 8; i++){
        int j = i-1;
        int temp = arr[i];
        while(j >= 0){
            if(temp < arr[j]){
                arr[j+1] = arr[j];
            }
            else break;
            j--;
        }
        arr[j+1] = temp;
    }
    for(int i = 0; i < 8; i++){
        printf("%d \n", arr[i]);
    }
    return 0;
}
