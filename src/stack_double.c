#include "stack_double.h"

stack_double* d_init() {
    stack_double* temp = (stack_double*)malloc(sizeof(stack_double));
    temp->value = 0;
    temp->next = NULL;
    return temp;
}

void d_push(stack_double** head, double val) {
    stack_double* temp = (stack_double*)malloc(sizeof(stack_double));
    temp->value = val;
    temp->next = *head;
    *head = temp;
}

double d_pop(stack_double** head) {
    double value = (*head)->value;
    stack_double* temp = *head;
    (*head) = (*head)->next;
    free(temp);
    return value;
}

void d_destroy(stack_double** head) {
    while (*head) {
        stack_double* temp = *head;
        (*head) = (*head)->next;
        free(temp);
    }
}
