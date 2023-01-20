#include "maths.h"

int fact(int num){
    if(num <= 1)return num;
    else return num * fact(num-1);
}