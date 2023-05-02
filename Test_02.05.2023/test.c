#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    long value;
    struct ListNode *next;
};

typedef struct {
    int size;
    struct ListNode *head;
} LinkedList;

struct ListNode *create_node(LinkedList *list, long value) {
    struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    if (newNode == NULL) {
        printf("Error allocating memory!");
        return NULL;
    }
    newNode->value = value;
    return newNode;
}

LinkedList init() {
    LinkedList list = {size: 0, head: NULL};
    return list;
}

void push_front(LinkedList *list, long value) {
    struct ListNode *newNode = create_node(list, value);
    if (newNode == NULL) {
        printf("Cannot push NULL \n");
        return;
    }
    newNode->next = list->head;
    list->head = newNode;
    list->size++;
}

long pop_front(LinkedList *list) {
    struct ListNode *currentNode = list->head;
    list->head = currentNode->next;
    long value = currentNode->value;
    free(currentNode);
    list->size--;
    return value;
}

struct ListNode *get(LinkedList *list, int index) {
    struct ListNode *current = list->head;
    for(int i = 0; i < index && i < list->size; i++) {
        current = current->next;
    }
    return current;
}

void printlinkedlist(LinkedList *list) {
    struct ListNode *current = list->head;
    for(int i = 0; current != NULL; i++){
        printf("%ld ", current->value);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    LinkedList list = init();

    push_front(&list, 10);
    push_front(&list, 11);
    push_front(&list, 12);
    printlinkedlist(&list);

    struct ListNode *current = get(&list, 1);
    printf("Index 1 value = %ld \n", current->value);

    pop_front(&list);
    pop_front(&list);
    printlinkedlist(&list);

    return 0;
}