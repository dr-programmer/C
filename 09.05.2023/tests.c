#include <stdio.h>
#include "duallinkedlist.h"

void printlist(LinkedList *list){
    struct ListNode *current = list->head;
    while (current != NULL){
        printf("%lf ", current->value);
        current = current->next;
    }
    printf("\n");
}

int main()
{

    LinkedList list = init();
    printlist(&list);
    
    pushfront(&list, 3);
    pushfront(&list, 5);
    pushfront(&list, 7);
    pushfront(&list, 2);
    printlist(&list);

    printf("Previous from index 1: %lf \n", list.head->next->prev->value);

    struct ListNode *el1 = get(&list, 1);
    printf("Element 1: %lf \n", el1->value);

    push(&list, 1, 11);
    printlist(&list);

    printf("Previous from index 3: %lf \n", list.head->next->next->next->prev->value);

    pushback(&list, 13);
    printlist(&list);

    double firstel = popfront(&list);
    printf("First element: %lf \n", firstel);
    printlist(&list);

    double el3 = pop(&list, 2);
    printf("Third element: %lf \n", el3);
    printlist(&list);

    printf("Previous from index 2: %lf \n", list.head->next->next->prev->value);

    double lastelement = popback(&list);
    printf("Last element: %lf \n", lastelement);
    printlist(&list);

    set(&list, 2, 17);
    printlist(&list);

    printf("Previous from index 1: %lf \n", list.head->next->prev->value);

    release(&list);
    printlist(&list);

    return 0;
}