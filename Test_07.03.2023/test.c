#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int rows, columns;
    do {
        printf("Please enter the number of rows: ");
        scanf("%d", &rows);
    } while(rows < 0);
    do {
        printf("Please enter the number of columns: ");
        scanf("%d", &columns);
    } while(columns < 0);

    int **p = (int **)calloc(rows, sizeof(int *));
    if (p == NULL){
        printf("Error allocating memory!");
        exit(-1);
    }
    for(int i = 0; i < rows; i++){
        *(p+i) = (int*)calloc(columns, sizeof(int));
        if (*(p+i) == NULL){
            printf("Error allocating memory!");
            exit(-1);
        }
    }

    int count = 1;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            *(*(p + i)+j) = count;
            count++;
        }
    }

    for(int i = 0; i < columns; i++){
        for(int j = 0; j < rows; j++){
            printf("%d ", *(*(p+j)+i));
        }
    }

    for(int i = 0; i < rows; i++){
        if(p != NULL && *(p+i) != NULL)free(*(p+i));
    }
    if(p != NULL)free(p);

    return 0;
}