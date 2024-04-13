CC = gcc
FLAGS = -Wall -Werror -Wextra
BUILD = ../build/

all: graph.c polish_notation.c stack.c stack_double.c separate_string.c graph_processing.c polish_notation.h stack.h stack_double.h separate_string.h graph_processing.h
	$(CC) $(FLAGS) graph.c polish_notation.c stack.c stack_double.c separate_string.c graph_processing.c -o $(BUILD)graph

clean:
	rm -rf *.o $(BUILD)graph

rebuild: clean all