#include <stdio.h>

#define OPTIONS_COUNT 3

typedef struct {
    char name[30];
    void (*procedure)(void);
} MenuOption;

void option1(void){
    printf("Executing option 1 \n");
}

void option2(void){
    printf("Executing option 2 \n");
}

void option3(void){
    printf("Executing option 3 \n");
}

void printmenu(MenuOption options[], int optioncount){
    printf("---------------------\n");
    for (int i = 0; i < optioncount; i++){
        printf("%d. %s\n", i + 1, options[i].name);
    }
    printf("0. Exit\n");
    printf("---------------------\n");
}

void startmenu(MenuOption options[], int optioncount){
    while(1){
        int choice = 0;
        do {
            printmenu(options, optioncount);
            printf("Please select an option (0-%d)", optioncount);
            scanf("%d", &choice);
        } while(choice < 0 || choice > optioncount);

        if(choice == 0)break;
        options[choice-1].procedure();
    }
}

int main()
{
    MenuOption temp = {"Hello", option1};

    MenuOption options[OPTIONS_COUNT] = {
        {"Option 1", option1},
        {"Option 2", option2},
        {"Option 3", option3}
    };
    
    startmenu(options, OPTIONS_COUNT);

    return 0;
}