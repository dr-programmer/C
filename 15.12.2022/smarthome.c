#include <stdio.h>

int main()
{
    int rooms = 0;
    while(1){
        char option = 0;
        printf("Switch ligths = 1, Print state = 2, Press any other key to close \n");
        scanf("%d", &option);
        if(option == 1){
            int room;
            printf("Type the number of the room: ");
            scanf("%d", &room);
            rooms = rooms ^ (1 << room-1);
        }
        else if(option == 2){
            printf("The light is on in: ");
            for(int i = 0; i < 8; i++){
                if(((1 << i) & rooms) != 0){
                    printf("%d ", i+1);
                }
            }
            printf("\n");
        }
        else break;
    }
    return 0;
}