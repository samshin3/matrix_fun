#include "matrix.h"

// defining a structure for the matrix to store all values for easy traversal of matrix
struct matrix {
    int m;
    int n;
    int **vals;
};

// allocates memory for an m x n matrix
struct matrix *create_matrix(int m, int n) {
    struct matrix *new_matrix = malloc(sizeof(struct matrix));
    new_matrix->m = m;
    new_matrix->n = n;
    new_matrix->vals = malloc(sizeof(int *) * new_matrix->m);
    for (int i = 0; i < new_matrix->m; i++) {
        new_matrix->vals[i] = malloc(sizeof(int) * new_matrix->n);
    }
    return new_matrix;
}


// a function that does matrix multiplication given two valid matrices.
// two matrices are valid if the number of columns in m1 are the same as 
// the number of rows in m2
struct matrix *matrix_multiply(struct matrix *m1, struct matrix *m2) {
    assert(m1->n == m2->m);
    struct matrix *result = create_matrix(m1->m, m2->n);
    for (int row = 0; row < result->m; row++) {
        for (int col = 0; col < result->n; col++) {
            result->vals[row][col] = 0;
        }
    }

    for (int row = 0; row < m1->m; row++) {
        for (int col = 0; col < m2->n; col++) {
            for (int i = 0; i < m1->n; i++) {
                result->vals[row][col] += m1->vals[row][i] * m2->vals[i][col];
            }
        }
    }
    return result;
}

// function to print a given matrix with borders
void print_matrix(struct matrix *grid) {
    assert(grid);
    for (int row = 0; row < grid->m; row++) {
        printf("|");
        for (int col = 0; col < grid->n; col++) {
            printf("%d ", grid->vals[row][col]);
        }
        printf("|\n");
    }
}

// calls user input to fill in the matrix given
void fill_matrix(struct matrix *grid) {
    for (int row = 0; row < grid->m; row++) {
        for (int col = 0; col < grid->n; col++) {
            scanf("%d", &(grid->vals[row][col]));
        }
    }
}

// call function to destroy a matrix
void destroy_matrix(struct matrix *grid) {
    assert(grid);
    for (int rows = 0; rows < grid->m; rows++) {
        free(grid->vals[rows]);
    }
    free(grid->vals);
    free(grid);
}