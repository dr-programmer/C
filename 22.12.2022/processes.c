#include <stdio.h>
#include <limits.h>
#include <string.h>

#include "processes.h"

struct Process processes[MAX_SIZE];
char processescount = 0;

static unsigned int nextprocessid(){
    static unsigned int uniqueid;
    if(uniqueid == UINT_MAX)return 0;
    else {
        uniqueid++;
        return uniqueid;
    }
}


unsigned int createnewprocess(char *name){
    if(processescount < MAX_SIZE){
        processes[processescount].id = nextprocessid();
        strcpy(processes[processescount].name, name);
        processescount++;
        return processes[processescount-1].id;
    }
    else return 0;
}

void stopprocess(unsigned int thisid){
    if(thisid < MAX_SIZE && thisid > 0){
        int deletethis;
        for(int i = 0; i < MAX_SIZE; i++){
            if(processes[i].id == thisid){
                deletethis = i;
                processes[deletethis].id = 0;
                strcpy(processes[deletethis].name, "");
                for(int j = deletethis; j < processescount; j++){
                    processes[j] = processes[j+1];
                }
                processescount--;
                break;
            }
        }
    }
}

