#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

static struct ListNode *createnode(Book value) {
    struct ListNode *newnode = (struct ListNode *)malloc(sizeof(struct ListNode));
    if (newnode == NULL) {
        printf("Error allocating memory! \n");
        exit(-1);
    }
    newnode->value = value;
    return newnode;
}

LinkedList init() {
    LinkedList list = {size: 0, head: NULL};
    return list;
}

struct ListNode *get(LinkedList *list, int index) {
    if (index < 0 || index >= list->size){
        return NULL;
    }
    struct ListNode *current = list->head;
    for(int i = 0; i < index; i++){
        current = current->next;
    }

    return current;
}

void push(LinkedList *list, int index, Book value) {
    if (index == 0) {
        pushfront(list, value);
        return;
    }
    struct ListNode *prevnode = get(list, index - 1);
    struct ListNode *newnode = createnode(value);
    newnode->next = prevnode->next;
    prevnode->next = newnode;
    list->size++;
}

void pushback(LinkedList *list, Book value) {
    push(list, list->size, value);
}

void pushfront(LinkedList *list, Book value) {
    struct ListNode *newnode = createnode(value);
    newnode->next = list->head;
    list->head = newnode;
    list->size++;
}

Book pop(LinkedList *list, int index) {
    if (index == 0){
        return popfront(list);
    }
    struct ListNode *prevnode = get(list, index - 1);
    struct ListNode *elementtodelete = prevnode->next;
    prevnode->next = prevnode->next->next;
    list->size--;

    Book result = elementtodelete->value;
    free(elementtodelete);

    return result;
}

Book popfront(LinkedList *list) {
    struct ListNode *elementtodelete = list->head;
    list->head = list->head->next;
    list->size--;

    Book result = elementtodelete->value;
    free(elementtodelete);

    return result;
}

Book popback(LinkedList *list) {
    return pop(list, list->size - 1);
}

void set(LinkedList *list, int index, Book value) {
    struct ListNode *node = get(list, index);
    node->value = value;
}

void release(LinkedList *list){
    while(list->size > 0){
        popback(list);
    }
}