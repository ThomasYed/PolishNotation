#ifndef SEPARATE_STRING_H
#define SEPARATE_STRING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int input_to_char_array(char ***res, int *size, char **newarray);
int words_count(char *str);
char **split(char *str, int *len);
char *input(size_t *array_len, int *bad);
char *makenewarr(char *datascan, int array_len);

#endif