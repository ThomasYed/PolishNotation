#include "graph_processing.h"

#include "polish_notation.h"

#define PoleX 80
#define PoleY 25

double calculate_y(char **p, int pol_size, double x) {
    char **pol_with_x = malloc(pol_size * sizeof(char *));
    char temp[256];
    sprintf(temp, "%lf", x);
    for (int i = 0; i < pol_size; i++) {
        if (strchr(p[i], 'x') != NULL) {
            pol_with_x[i] = temp;
        } else
            pol_with_x[i] = p[i];
    }
    double result;
    count_by_polish(pol_with_x, pol_size, &result);
    free(pol_with_x);
    return result;
}

int scale(double y) {
    int ans = 0;
    if (-1 <= y && y <= 1) ans = lround((y + 1.0) / 2.0 * 25);
    return ans;
}

int *y_array(char **p, int pol_size) {
    int *y_arr = calloc(80, sizeof(int));
    int i = 0;
    for (double x = 0; x <= M_PI * 4; x += M_PI * 4 / 80, i++) y_arr[i] = scale(calculate_y(p, pol_size, x));
    return y_arr;
}

void draw_graph(const int *array_point) {
    printf("\033[H\033[J");

    for (int i = 0; i < PoleY; i++) {
        for (int j = 0; j < PoleX; j++) {
            if (array_point[j] != 0 && array_point[j] == i)
                printf("*");
            else
                printf(".");
        }
        printf("\n");
    }
}
