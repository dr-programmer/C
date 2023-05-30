#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define REMOVE_NEW_ROW(STRING, POINTER) POINTER = strchr(STRING, '\n'); *POINTER = '\0';

typedef struct {
    char EGN[11];
    char names[255];
    unsigned char age;
    unsigned char education;
    unsigned char workingStatus;
    unsigned char familyStatus;
} Citizen;

int main(int argc, char **argv)
{
    char *filename = argv[1];

    int count;
    FILE *file = fopen("test.bin", "rb");
    if(file == NULL) {
        count = 0;
    }
    else {
        fread(&count, sizeof(int), 1, file);
        fclose(file);
        printf("Count = %d", count);
    }

    int option;
    while(1) {
        printf("1: Add citizen; 2: Remove citizen by EGN; 3: Show all citizens \n");
        scanf("%d", &option);
        switch(option) {
            case 1: {
                Citizen citizen;
                getchar();
                printf("Name: ");
                fgets(citizen.names, 255, stdin);
                char *p;
                REMOVE_NEW_ROW(citizen.names, p);
                printf("EGN: ");
                fgets(citizen.EGN, 11, stdin);
                REMOVE_NEW_ROW(citizen.EGN, p);
                printf("Age: ");
                scanf("%d", &citizen.age);
                printf("1: No education; 2: Primary; 3: High; 4: University");
                scanf("%d", &citizen.education);
                printf("1: With a job; 2: Without a job");
                scanf("%d", &citizen.workingStatus);
                printf("1: Married; 2: Not married");
                scanf("%d", &citizen.familyStatus);

                FILE *file = fopen("test.bin", "ab+");
                count++;
                Citizen *citizens = (Citizen *)calloc(count, sizeof(Citizen));
                fread(&citizens, sizeof(Citizen), count-1, file);
                citizens[count-1] = citizen;
                fclose(file);
                file = fopen("test.bin", "wb");
                fwrite(&count, sizeof(int), 1, file);
                fwrite(&citizens, sizeof(Citizen), count, file);
                fclose(file);
                break;
            }
            case 2: {
                char *p;
                char EGN[11];
                printf("EGN: ");
                fgets(EGN, 11, stdin);
                REMOVE_NEW_ROW(EGN, p);
                FILE *file = fopen("test.bin", "ab+");
                Citizen *citizens = (Citizen *)calloc(count, sizeof(Citizen));
                fread(&citizens, sizeof(Citizen), count-1, file);
                fclose(file);
                int i;
                for(i = 0; i < count; i++) {
                    if (citizens[i].EGN == EGN) {
                        break;
                    }
                }
                for(; i < count-1; i++) {
                    citizens[i] = citizens[i+1];
                }
                file = fopen("test.bin", "wb");
                fwrite(&citizens, sizeof(Citizen), count, file);
                fclose(file);
                free(citizens);
                break;
            }
            case 3: {
                FILE *file = fopen("test.bin", "rb");
                if (file == NULL)printf("Hi");
                Citizen *citizen = (Citizen *)calloc(count, sizeof(Citizen));
                int temp;
                fread(&temp, sizeof(int), 1, file);
                fread(&citizen, sizeof(Citizen), count, file);
                fclose(file);
                for(int i = 0; i < count; i++) {
                    printf("%s %s %d %d %d %d \n", citizen[i].EGN, citizen[i].names, citizen[i].age, \
                    citizen[i].education, citizen[i].workingStatus, citizen[i].familyStatus);
                }
                free(citizen);
                break;
            }
            default: exit(0);
        }
    }

    return 0;
}