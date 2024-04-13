#ifndef STACK_DOUBLE_H
#define STACK_DOUBLE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct stack_double {
    double value;
    struct stack_double* next;
} stack_double;

stack_double* d_init();
void d_push(stack_double** head, double val);
double d_pop(stack_double** head);
void d_destroy(stack_double** head);

#endif