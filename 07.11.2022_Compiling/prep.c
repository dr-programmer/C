/*
 *author:dtopuzov
 *license: MIT
*/
#include<stdio.h>
#define ARRAY_SIZE 5

// sum of elements
int main()
{
	int array[ARRAY_SIZE] = {1, 2, 3, 4, 5};
	int sum = 0;
	for(int i = 0; i < ARRAY_SIZE; i++){
		sum+= array[i];
	}
	
	return 0;
}
