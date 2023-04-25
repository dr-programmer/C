#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "linkedlist.h"

void printTodos(LinkedList *todos) {
    struct ListNode *currentTodo = todos->head;
    for(int i = 0; i < todos->size; i++){
        printf("Priority: %d Description: %-30s ", i+1, currentTodo->value.description);
        switch(currentTodo->value.state){
            case new: printf("State new \n"); break;
            case started: printf("State started \n"); break;
            case done: printf("State done \n"); break;
        }
    }
}

int main()
{
    LinkedList todos = init();
    while(1){
        int choice;
        printf("1: Add a task; 2: Change task state; 3: Show all tasks; 4: Delete a task; \n");
        scanf("%d", &choice);
        switch(choice){
            case 1: {
                Todo todo;
                printf("Description: \n");
                getchar();
                fgets(todo.description, 99, stdin);
                char *p = strchr(todo.description, '\n');
                *p = '\0';
                int priority;
                printf("Priority: \n");
                scanf("%d", &priority);
                todo.state = new;
                push(&todos, priority-1, todo);
                break;
            }
            case 2: {
                int priority;
                printf("Enter the priority of the task: \n");
                scanf("%d", &priority);
                int state;
                printf("0: new, 1: started, 2: done \n");
                scanf("%d", &state);
                struct ListNode* changedNode = get(&todos, priority-1);
                changedNode->value.state = state;
                break;
            }
            case 3: {
                printTodos(&todos);
                break;
            }
            case 4: {
                int priority;
                printf("Enter the priority of the task: \n");
                scanf("%d", &priority);
                pop(&todos, priority-1);
                break;
            }
            default: exit(-1);
        }
    }

    return 0;
}