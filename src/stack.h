#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    char* value;
    struct stack* next;
} stack;

stack* init();
void push(stack** head, char* val);
char* pop(stack** head);
char* peek(stack** head);
void destroy(stack** head);
int length(stack** head);
char** stack_to_array(stack** head);

#endif