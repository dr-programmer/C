#include <stdio.h>
#include <stdlib.h>

#include "bitstate.h"

int main()
{
    while(1){
        unsigned char option;
        printf("\n1: Turn on a diode; 2: Turn off a diode; 3: Toggle a diode; 4: Show if the diode is on; 5: Print all the diodes' states; 6: close \n");
        scanf("%d", &option);
        switch (option){
            case 1:
            {
                unsigned char diode;
                printf("Please enter the number of the diode: ");
                scanf("%d", &diode);
                setbit(diode-1);
                break;
            }
            case 2:
            {
                unsigned char diode;
                printf("Please enter the number of the diode: ");
                scanf("%d", &diode);
                unsetbit(diode-1);
                break;
            }
            case 3:
            {
                unsigned char diode;
                printf("Please enter the number of the diode: ");
                scanf("%d", &diode);
                togglebit(diode-1);
                break;
            }
            case 4:
            {
                unsigned char diode;
                printf("Please enter the number of the diode: ");
                scanf("%d", &diode);
                char bit = isbitset(diode-1);
                printf("\nThe state of diode %d is %d", diode, bit);
                break;
            }
            case 5:
            {
                for(int i = 0; i < 32; i++){
                    int bit = 0;
                    bit = isbitset(i);
                    printf("Bit #%d: %d \n", i+1, bit);
                }
                break;
            }
            default:
                exit(0);
        }
    }
    return 0;
}