#ifndef GRAPH_PROC_H
#define GRAPH_PROC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double calculate_y(char **p, int pol_size, double x);
int *y_array(char **p, int pol_size);
void draw_graph(const int *array_point);

#endif
