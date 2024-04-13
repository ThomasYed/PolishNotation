#include "stack.h"

stack* init() {
    stack* temp = (stack*)malloc(sizeof(stack));
    temp->value = "";
    temp->next = NULL;
    return temp;
}

void push(stack** head, char* val) {
    stack* temp = (stack*)malloc(sizeof(stack));
    temp->value = val;
    temp->next = *head;
    *head = temp;
}

char* pop(stack** head) {
    char* value = (*head)->value;
    stack* temp = *head;
    (*head) = (*head)->next;
    free(temp);
    return value;
}

char* peek(stack** head) { return (*head)->value; }

void destroy(stack** head) {
    while (*head) {
        stack* temp = *head;
        (*head) = (*head)->next;
        free(temp);
    }
}

int length(stack** head) {
    int len = 0;
    stack* temp = *head;
    while (temp) {
        len++;
        temp = temp->next;
    }
    return len - 1;
}

char** stack_to_array(stack** head) {
    int len = length(head);
    char** arr = malloc(sizeof(char*) * len);
    int i = len - 1;
    stack* temp = *head;
    while (temp && *(temp->value) != '\0') {
        arr[i] = temp->value;
        i--;
        temp = temp->next;
    }

    return arr;
}