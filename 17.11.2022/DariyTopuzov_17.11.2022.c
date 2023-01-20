/*
#define MACRO(A, B) (A + B) * (A + B)

int main()
{
    int result = MACRO(5, 10);
    return 0;
}
*/

#include <stdio.h>
/*
int main()
{
	int x = 12, y = 18, res;
	res = (x > y) ? x : y;

	while (1) {
		if (res % x == 0 && res % y == 0) {
			break;
		}
		res++;
	}
    printf("%d \n", res);
    return 0;
}
*/
#include <math.h>
int main()
{
    long arr[] = {1,2,3,4,5,6};
    for(int i = 0; i < 6; i++){
        arr[i] = pow(arr[i], 4);
    }
    return 0;
}

