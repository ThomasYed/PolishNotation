#include "separate_string.h"

int input_to_char_array(char ***res, int *size, char **newarray) {
    size_t array_len = 20;
    int bad = 0;
    char *datascan = input(&array_len, &bad);
    if (!bad) {
        *newarray = makenewarr(datascan, array_len);
        *res = split(*newarray, size);
    }
    free(datascan);
    return bad;
}

int words_count(char *str) {
    int c = 1;
    for (char *p = str; *p; p++) c += (*p) == ' ';
    return c;
}

char **split(char *str, int *len) {
    char **res = calloc(words_count(str), sizeof(char *));
    char *pch = strtok(str, " ");
    int i = 0;
    while (pch != NULL) {
        res[i] = pch;
        i++;
        pch = strtok(NULL, " ");
    }
    *len = i;
    return res;
}

char *input(size_t *array_len, int *bad) {
    char *datascan = (char *)calloc(*array_len, sizeof(char));
    char ch;
    size_t i = 0;
    printf("Введите значение:");
    while (!(*bad) && ((ch = getchar()) != '\n' && ch != '\0')) {
        if (i < *array_len) {
            datascan[i] = ch;
            ++i;
        } else {
            *array_len *= 2;
            char *new_arr = realloc(datascan, (*array_len) * sizeof(char));
            if (new_arr) {
                datascan = new_arr;
                new_arr = NULL;
                datascan[i] = ch;
                ++i;
            } else
                *bad = 1;
        }
    }
    return datascan;
}

char *makenewarr(char *datascan, int array_len) {
    char *newarray = (char *)calloc(array_len * 2 + 5, sizeof(char));
    size_t j = 0;
    for (size_t i = 0; i != strlen(datascan); ++i) {
        switch (datascan[i]) {
            case '-':
                if (!i) {
                    newarray[j++] = '-';
                    newarray[j++] = ' ';
                } else if (datascan[i - 1] == ' ') {
                    newarray[j++] = datascan[i];
                    newarray[j++] = ' ';
                } else {
                    newarray[j++] = ' ';
                    newarray[j++] = datascan[i];
                    newarray[j++] = ' ';
                }
                break;
            case '+':
                if (datascan[i - 1] == ' ') {
                    newarray[j++] = datascan[i];
                    newarray[j++] = ' ';
                } else {
                    newarray[j++] = ' ';
                    newarray[j++] = datascan[i];
                    newarray[j++] = ' ';
                }
                break;
            case '*':
                if (datascan[i - 1] == ' ') {
                    newarray[j++] = datascan[i];
                    newarray[j++] = ' ';
                } else {
                    newarray[j++] = ' ';
                    newarray[j++] = datascan[i];
                    newarray[j++] = ' ';
                }
                break;
            case '/':
                if (datascan[i - 1] == ' ') {
                    newarray[j++] = datascan[i];
                    newarray[j++] = ' ';
                } else {
                    newarray[j++] = ' ';
                    newarray[j++] = datascan[i];
                    newarray[j++] = ' ';
                }
                break;
            case ')':
                if (datascan[i - 1] == '*' || datascan[i - 1] == '/' || datascan[i - 1] == '+' ||
                    datascan[i - 1] == '-') {
                    newarray[j++] = datascan[i];
                    newarray[j++] = ' ';
                } else if (datascan[i + 1] == '*' || datascan[i + 1] == '/' || datascan[i + 1] == '+' ||
                           datascan[i + 1] == '-') {
                    newarray[j++] = ' ';
                    newarray[j++] = datascan[i];
                } else {
                    newarray[j++] = ' ';
                    newarray[j++] = datascan[i];
                    newarray[j++] = ' ';
                }
                break;
            case '(':
                if (datascan[i - 1] == '*' || datascan[i - 1] == '/' || datascan[i - 1] == '+' ||
                    datascan[i - 1] == '-') {
                    newarray[j++] = datascan[i];
                    newarray[j++] = ' ';
                } else if (datascan[i + 1] == '*' || datascan[i + 1] == '/' || datascan[i + 1] == '+' ||
                           datascan[i + 1] == '-') {
                    newarray[j++] = ' ';
                    newarray[j++] = datascan[i];
                } else {
                    newarray[j++] = ' ';
                    newarray[j++] = datascan[i];
                    newarray[j++] = ' ';
                }
                break;
            default:
                newarray[j++] = datascan[i];
        }
    }
    return newarray;
}