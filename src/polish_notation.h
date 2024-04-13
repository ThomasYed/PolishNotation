#ifndef POLISH_NOTATION_H
#define POLISH_NOTATION_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"
#include "stack_double.h"

#define OPERATORS "+", "-", "*", "/", ")", "(", "sin", "cos", "tan", "ctg", "sqrt", "ln"
#define UNAR "sin", "cos", "tan", "ctg", "sqrt", "ln"

int is_operator(char *s);
int is_brace(char *s);
int is_unar(char *s);
int is_plusmin(char *s);
int is_unar_minus(char **a, int i);
int cmpbin(char *s1, char *s2);
int cmp(char *s1, char *s2);
void operators_shift(char *operator, stack ** pol, stack **s);
double to_num(char *str);
void unar_apply(double *num, char *operator);
void unar_calc(stack_double **st, char *operator);
void binar_apply(double *num1, double num2, char *operator);
void binar_calc(stack_double **st, char *operator);
int calculate(stack_double **st, char *operator);

char **polish(char **a, int n, int *pol_size);
int count_by_polish(char **pol, int pol_size, double *result);

#endif