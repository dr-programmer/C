#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linkedlist.h"

#define R_NROW(STRING) p = strchr(STRING, '\n'); \
                        if(p != NULL) *p = '\0';

void printlist(LinkedList *list){
    struct ListNode *current = list->head;
    while (current != NULL){
        printf("%s %s %s %d %d \n", current->value.name, current->value.author, current->value.genre, current->value.year, current->value.isbn);
        current = current->next;
    }
}

int deleteByISBN(LinkedList *list, int isbn) {
    for(int i = 0; i < list->size; i++) {
        struct ListNode *node = get(list, i);
        if (node->value.isbn == isbn) {
            pop(list, i);
            return i;
        }
    }
    return -1;
}

int main()
{
    FILE *library = fopen("library.txt", "a+");
    if(library == NULL) {
        printf("Cannot read file\n");
        exit(0);
    }

    LinkedList list = init();
    Book book;
    while(fscanf(library, "%d %d\n", &book.year, &book.isbn) > 0) {
        char *p;
        fgets(book.name, 50, library);
        R_NROW(book.name);
        fgets(book.author, 30, library);
        R_NROW(book.author);
        fgets(book.genre, 30, library);
        R_NROW(book.genre);
        pushback(&list, book);
    }

    fclose(library);

    int choice;
    char exit = 0;
    while(!exit) {
        printf("1: Add a book; 2: Show all books; 3: Delete by isbn number; 4: Save; 5: Close");
        scanf("%d", &choice);
        switch(choice) {
            case 1: {
                getchar();
                char *p;
                Book temp;
                printf("Name: ");
                fgets(temp.name, 50, stdin);
                R_NROW(temp.name);
                printf("Author: ");
                fgets(temp.author, 30, stdin);
                R_NROW(temp.author);
                printf("Genre: ");
                fgets(temp.genre, 30, stdin);
                R_NROW(temp.genre);
                printf("Year: ");
                scanf("%d", &temp.year);
                printf("ISBN: ");
                scanf("%d", &temp.isbn);
                pushback(&list, temp);
                break;
            }
            case 2: {
                printlist(&list);
                break;
            }
            case 3: {
                int temp;
                printf("Enter the isbn of the book to delete: ");
                scanf("%d", &temp);
                deleteByISBN(&list, temp);
                break;
            }
            case 4: {
                library = fopen("library.txt", "w");
                if(library == NULL) {
                    printf("Cannot read file\n");
                    exit = 1;
                    break;
                }
                for (int i = 0; i < list.size; i++) {
                    struct ListNode *node = get(&list, i);
                    fprintf(library, "%d %d\n", node->value.year, node->value.isbn);
                    fprintf(library, "%s\n", node->value.name);
                    fprintf(library, "%s\n", node->value.author);
                    fprintf(library, "%s\n", node->value.genre);
                }
                break;
            }
            default: {
                exit = 1;
                break;
            }
        }
    }

    release(&list);
    fclose(library);

    return 0;
}