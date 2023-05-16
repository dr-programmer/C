#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct {
    char name[50];
    char author[30];
    char genre[30];
    int year;
    int isbn;
} Book;

struct ListNode {
    Book value;
    struct ListNode *next;
};

typedef struct {
    int size;
    struct ListNode *head;
} LinkedList;

LinkedList init();

struct ListNode *get(LinkedList *list, int index);

void push(LinkedList *list, int index, Book value);
void pushback(LinkedList *list, Book value);
void pushfront(LinkedList *list, Book value);

Book pop(LinkedList *list, int index);
Book popfront(LinkedList *list);
Book popback(LinkedList *list);

void set(LinkedList *list, int index, Book value);

void release(LinkedList *list);

#endif