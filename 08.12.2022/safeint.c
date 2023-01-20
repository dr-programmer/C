#include <stdio.h>
#include <limits.h>

#include "safeint.h"

struct SafeResult safeadd(int a, int b){
    struct SafeResult result;
    result.value = a+b;
    if(a > (INT_MAX-b) || a < (INT_MIN+b)){
        result.errorflag = 1;
    }
    if(b > (INT_MAX-a) || b < (INT_MIN+a)){
        result.errorflag = 1;
    }
    return result;
}
struct SafeResult safesubtract(int a, int b){
    struct SafeResult result;
    result.value = a-b;
    if(a > (INT_MAX) || a < (INT_MIN+b)){
        result.errorflag = 1;
    }
    if(b > (INT_MAX) || b < (INT_MIN+a)){
        result.errorflag = 1;
    }
    return result;
}
struct SafeResult safemultiply(int a, int b){
    struct SafeResult result;
    result.value = a*b;
    if(a > (INT_MAX/b) || a < (INT_MIN*b)){
        result.errorflag = 1;
    }
    if(b > (INT_MAX/a) || b < (INT_MIN*a)){
        result.errorflag = 1;
    }
    return result;
}
struct SafeResult safedivide(int a, int b){
    struct SafeResult result;
    result.value = a/b;
    if(a > (INT_MAX) || a < (INT_MIN*b)){
        result.errorflag = 1;
    }
    if(b > (INT_MAX) || b < (INT_MIN*a)){
        result.errorflag = 1;
    }
    return result;
}
struct SafeResult safestrtoint(char *string){
    struct SafeResult result;
    result.value = 0;
    int i = 0, flag = 1;
    if(string[i] == '+'){
        i = 1;
    }
    else if(string[i] == '-'){
        i = 1;
        flag = -1;
    }
    for(i; string[i] != '\0'; i++){
        result = safeadd(result.value, (string[i] - '0'));
        result = safemultiply(result.value, 10);
    }
    result.value /= 10;
    result.value *= flag;
    return result;
}