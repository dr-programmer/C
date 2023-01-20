#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "processes.h"

int main()
{
    while(1){
        unsigned char option;
        printf("1: Create new process; 2: Show all running processes; 3: Terminate a process; 4: Close \n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            char name[31];
            printf("Wirte the name of the process you want to create: ");
            getchar();
            fgets(name, 30, stdin);
            if(processescount < MAX_SIZE)createnewprocess(name);
            else printf("Error: Too many processes are running at the moment! \n");
            break;
        
        case 2:
            for(int i = 0; i < processescount; i++){
                printf("%d: ", processes[i].id);
                puts(processes[i].name);
                printf("\n");
            }
            break;

        case 3:
            unsigned int terminate;
            printf("Write the id of the process you want to terminate: ");
            scanf("%u", &terminate);
            stopprocess(terminate);
            break;

        default:
            exit(0);
            break;
        }
    }
    return 0;
}