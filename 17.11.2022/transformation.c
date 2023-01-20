#include <string.h>
#include "transformation.h"

struct transformation chartolong(char *string){
    int symbol = 1;
    long result = 0;
    char error[100] = "\0";
    for(int i = 0; string[i] != '\0'; i++){
        if((string[i]-48 >= 0 && string[i]-48 <= 9) || ((string[i] == '-' || string[i] == '+') && i == 0)){
            if(string[i] == '-'){
                symbol = -1;
            }
            else {
                result = (string[i] - 48) + result;
                result *= 10;
            }
        }
        else {
            strcpy(error, "Invalid input string!");
            result = 0;
            break;
        }
    }
    struct transformation rt;
    rt.result = (result/10) * symbol;
    strcpy(rt.error, error);
    return rt;
}