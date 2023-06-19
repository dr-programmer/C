#include <stdio.h>

#include "linkedlist.h"

typedef struct {
    LinkedList list;
} Stack;

Stack initStack() {
    Stack stack;
    stack.list = init();
    return stack;
}

void pushStack(Stack *stack, double value) {
    pushfront(&stack->list, value);
}

double popStack(Stack *stack) {
    return popfront(&stack->list);
}

int lenStack(Stack *stack) {
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
    Stack stack = initStack();
    pushStack(&stack, 1);
    printlist(&stack.list);
    pushStack(&stack, 2);
    printlist(&stack.list);
    pushStack(&stack, 3);
    printlist(&stack.list);

    popStack(&stack);
    printlist(&stack.list);
    popStack(&stack);
    printlist(&stack.list);
    popStack(&stack);
    printlist(&stack.list);

    return 0;
}