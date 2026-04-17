#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

struct matrix;

struct matrix *create_matrix(int m, int n);

struct matrix *matrix_multiply(struct matrix *m1, struct matrix *m2);

void print_matrix(struct matrix *grid);

void destroy_matrix(struct matrix *grid);

// Intended for 2x2 matrix
struct matrix *invert_matrix(struct matrix *mat);

void fill_matrix(struct matrix *grid);

float det(struct matrix *mat);

void scalar_multiply(struct matrix *mat, float scalar);

struct matrix *transpose(struct matrix *mat);

// employs method of least squares
struct matrix *linear_reg(struct matrix *x, struct matrix *y);
