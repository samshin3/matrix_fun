#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

struct matrix;

// Heap allocated, caller must free with destroy_matrix
struct matrix *create_matrix(int m, int n);

struct matrix *matrix_multiply(struct matrix *m1, struct matrix *m2);

void print_matrix(struct matrix *grid);

void destroy_matrix(struct matrix *grid);

// Heap allocated, caller must free
int *matrix_shape(struct matrix *mat);

int get_value(struct matrix *mat, int row, int col);

// Heap allocated, caller must free
struct matrix *invert_matrix(struct matrix *mat);

void fill_matrix(struct matrix *grid);

float det(struct matrix *mat);

void scalar_multiply(struct matrix *mat, float scalar);

// Heap allocated, caller must free with destroy_matrix
struct matrix *transpose(struct matrix *mat);

// employs method of least squares
// Heap allocated, caller must free with destroy_matrix
struct matrix *linear_reg(struct matrix *x, struct matrix *y);

// Heap allocated, caller must free with destroy_matrix
struct matrix *minor_matrix(struct matrix *mat, int i, int j);

// Heap allocated, caller must free with destroy_matrix
struct matrix *adj(struct matrix *mat);
