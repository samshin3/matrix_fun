#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

struct matrix;

struct matrix *create_matrix(int m, int n);

struct matrix *matrix_multiply(struct matrix *m1, struct matrix *m2);

void print_matrix(struct matrix *grid);

void destroy_matrix(struct matrix *grid);

