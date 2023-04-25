#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef enum {
    new,
    started,
    done
} State;

typedef struct {
    char description[100];
    State state;
} Todo;

struct ListNode {
    Todo value;
    struct ListNode *next;
};

typedef struct {
    int size;
    struct ListNode *head;
} LinkedList;

LinkedList init();

struct ListNode *get(LinkedList *list, int index);

void push(LinkedList *list, int index, Todo value);
void pushback(LinkedList *list, Todo value);
void pushfront(LinkedList *list, Todo value);

Todo pop(LinkedList *list, int index);
Todo popfront(LinkedList *list);
Todo popback(LinkedList *list);

void set(LinkedList *list, int index, Todo value);

void release(LinkedList *list);

#endif