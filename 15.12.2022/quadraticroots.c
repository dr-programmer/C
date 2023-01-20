#include <stdio.h>
#include <math.h>

#include "quadraticroots.h"

double squaretoor(double num){
    return num * num;
}

QuadraticRootsResult findroots(double a, double b, double c){
    QuadraticRootsResult result;
    double d;
    d = squaretoor(b) - (4 * a * c);
    if(d < 0){
        result.norealroots = 1;
        return result;
    }
    result.x1 = ((b * (-1)) + sqrtl(d))/(2 * a);
    result.x2 = ((b * (-1)) + (sqrtl(d) * (-1)))/(2 * a);
    return result;
}