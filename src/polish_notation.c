#include "polish_notation.h"

int is_operator(char *s) {
    char *operators[] = {OPERATORS};
    int n = sizeof(operators) / sizeof(char *);
    int flag = 0;
    for (int i = 0; i < n && !flag; i++)
        if (strcmp(operators[i], s) == 0) flag = 1;
    return flag;
}

int is_brace(char *s) { return (strcmp(s, ")") == 0) || (strcmp(s, "(") == 0); }

int is_unar(char *s) {
    char *unar[] = {UNAR};
    int n = sizeof(unar) / sizeof(char *);
    int flag = 0;
    for (int i = 0; i < n && !flag; i++)
        if (strcmp(unar[i], s) == 0) flag = 1;
    return flag;
}

int is_plusmin(char *s) { return strcmp(s, "+") == 0 || strcmp(s, "-") == 0; }

int cmpbin(char *s1, char *s2) { return !is_plusmin(s1) && is_plusmin(s2); }

int cmp(char *s1, char *s2) {
    int ans = 0;
    if (*s2 == '(' || *s2 == '\0')
        ans = 1;
    else {
        if (is_unar(s1)) {
            if (is_unar(s2))
                ans = 0;
            else
                ans = 1;
        } else {
            if (is_unar(s2))
                ans = 0;
            else
                ans = cmpbin(s1, s2);
        }
    }
    return ans;
}

int is_unar_minus(char **a, int i) {
    return ((*(a[i]) == '-') && ((i == 0) || (i > 0 && *(a[i - 1]) == '(')));
}

void operators_shift(char *operator, stack ** pol, stack **s) {
    if (!is_brace(operator)) {
        if (cmp(operator, peek(s)))
            push(s, operator);
        else {
            push(pol, pop(s));
            push(s, operator);
        }

    } else if (strcmp(operator, "(") == 0)
        push(s, operator);
    else if (strcmp(operator, ")") == 0) {
        while (*peek(s) != '(') push(pol, pop(s));
        pop(s);
    }
}

char **polish(char **a, int n, int *pol_size) {
    stack *pol = init();
    stack *s = init();
    for (int i = 0; i < n; i++) {
        if (is_unar_minus(a, i)) {
            push(&pol, "0");
            push(&s, a[i]);
        } else {
            if (!is_operator(a[i]))
                push(&pol, a[i]);
            else {
                operators_shift(a[i], &pol, &s);
            }
        }
    }
    while (*peek(&s) != '\0') push(&pol, pop(&s));
    *pol_size = length(&pol);
    char **polish_not = stack_to_array(&(pol));
    destroy(&pol);
    destroy(&s);
    return polish_not;
}

double to_num(char *str) { return strtod(str, NULL); }

void unar_apply(double *num, char *operator) {
    if (strcmp(operator, "sin") == 0)
        *num = sin(*num);
    else if (strcmp(operator, "cos") == 0)
        *num = cos(*num);
    else if (strcmp(operator, "tan") == 0)
        *num = tan(*num);
    else if (strcmp(operator, "ctg") == 0)
        *num = tan(M_PI / 2 - *num);
    else if (strcmp(operator, "sqrt") == 0)
        *num = sqrt(*num);
    else if (strcmp(operator, "ln") == 0)
        *num = log(*num);
}

void unar_calc(stack_double **st, char *operator) {
    double num = d_pop(st);
    unar_apply(&num, operator);
    d_push(st, num);
}

void binar_apply(double *num1, double num2, char *operator) {
    if (strcmp(operator, "+") == 0)
        *num1 = *num1 + num2;
    else if (strcmp(operator, "-") == 0)
        *num1 = *num1 - num2;
    else if (strcmp(operator, "*") == 0)
        *num1 = *num1 * num2;
    else if (strcmp(operator, "/") == 0)
        *num1 = *num1 / num2;
}

void binar_calc(stack_double **st, char *operator) {
    double num2 = d_pop(st);
    double num1 = 0;
    if (*st) num1 = d_pop(st);
    binar_apply(&num1, num2, operator);
    d_push(st, num1);
}

int calculate(stack_double **st, char *operator) {
    int bad = 0;

    if (*st && is_unar(operator)) {
        unar_calc(st, operator);
    } else if (*st && ((*st)->next || *operator== '-')) {
        binar_calc(st, operator);
    } else
        bad = 1;
    return bad;
}

int count_by_polish(char **pol, int pol_size, double *result) {
    int bad = 0;
    stack_double *st = d_init();
    if (is_operator(pol[0]))
        bad = 1;
    else
        st->value = to_num(pol[0]);
    for (int i = 1; !bad && i < pol_size; i++) {
        if (is_operator(pol[i])) {
            if (calculate(&st, pol[i])) bad = 1;
        } else {
            d_push(&st, to_num(pol[i]));
        }
    }
    *result = st->value;
    d_destroy(&st);
    return bad;
}
