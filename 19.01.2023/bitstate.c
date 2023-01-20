#include "bitstate.h"

static unsigned int bitstate;

void setbit(unsigned char bit){
    if(bit < 0 || bit > 31)return;
    bitstate = bitstate | (1 << bit);
}

void unsetbit(unsigned char bit){
    if(bit < 0 || bit > 31)return;
    bitstate = bitstate & (~(1 << bit));
}

void togglebit(unsigned char bit){
    if(bit < 0 || bit > 31)return;
    bitstate = bitstate ^ (1 << bit);
}

char isbitset(unsigned char bit){
    if(bit < 0 || bit > 31)return -1;
    if((bitstate & (1 << bit)) > 0)return 1;
    else return 0;
}

int getbitstate(){
    return bitstate;
}
