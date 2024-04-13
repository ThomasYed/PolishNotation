#include "graph_processing.h"
#include "polish_notation.h"
#include "separate_string.h"

int main() {
    char **res = NULL;
    int size = 0;
    char *buff = NULL;
    int bad = input_to_char_array(&res, &size, &buff);
    if (!bad) {
        char **pol = NULL;
        int pol_size = 0;
        pol = polish(res, size, &pol_size);

        int *y_arr = y_array(pol, pol_size);

        draw_graph(y_arr);

        free(y_arr);
        free(pol);
    } else {
        printf("n/a");
    }

    free(buff);
    free(res);

    return 0;
}