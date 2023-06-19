#include <stdio.h>

#include "linkedlist.h"

typedef struct {
    LinkedList list;
} Queue;

Queue initQueue() {
    Queue stack;
    stack.list = init();
    return stack;
}

void enQueue(Queue *stack, double value) {
    pushback(&stack->list, value);
}

double deQueue(Queue *stack) {
    return popfront(&stack->list);
}

int lenQueue(Queue *stack) {
    return stack->list.size;
}

void printlist(LinkedList *list){
    struct ListNode *current = list->head;
    while (current != NULL){
        printf("%lf ", current->value);
        current  = current->next;
    }
    printf("\n");
}

int main()
{
    Queue stack = initQueue();
    enQueue(&stack, 1);
    printlist(&stack.list);
    enQueue(&stack, 2);
    printlist(&stack.list);
    enQueue(&stack, 3);
    printlist(&stack.list);

    deQueue(&stack);
    printlist(&stack.list);
    deQueue(&stack);
    printlist(&stack.list);
    deQueue(&stack);
    printlist(&stack.list);

    return 0;
}