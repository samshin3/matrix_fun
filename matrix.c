#include "matrix.h"
#include <assert.h>

// defining a structure for the matrix to store all values for easy traversal of matrix
struct matrix {
    int m;
    int n;
    float **vals;
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
            printf("%f ", grid->vals[row][col]);
        }
        printf("|\n");
    }
    printf("\n");
}

// calls user input to fill in the matrix given
void fill_matrix(struct matrix *grid) {
    for (int row = 0; row < grid->m; row++) {
        for (int col = 0; col < grid->n; col++) {
            scanf("%f", &(grid->vals[row][col]));
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

float det(struct matrix *mat) {
	assert(mat);
	assert(mat->m <= 2);
	assert(mat->n <= 2);

	if (mat->m == 1) {
		return mat->vals[0][0]; // first and only entry in the matrix;
	}

	float a = mat->vals[0][0];
	float b = mat->vals[0][1];
	float c = mat->vals[1][0];
	float d = mat->vals[1][1];

	return (a * d) - (b * c);

}

void scalar_multiply(struct matrix *mat, float scalar) {
	assert(mat);

	for (int row = 0; row < mat->m; row++) {
		for (int col = 0; col < mat->n; col++) {
			mat->vals[row][col] *= scalar;
		}
	}

}

struct matrix *invert_matrix(struct matrix *mat) {
	assert(mat);
	assert(mat->m == 2);
	assert(mat->n == 2);

	float determinant = det(mat);

	assert(determinant != 0);

	float a = mat->vals[0][0];
	float b = mat->vals[0][1];
	float c = mat->vals[1][0];
	float d = mat->vals[1][1];	

	struct matrix * inverted = create_matrix(2, 2);

	inverted->vals[0][0] = d;
	inverted->vals[0][1] = -b;
	inverted->vals[1][0] = -c;
	inverted->vals[1][1] = a;

	scalar_multiply(inverted, (float) 1 / determinant);

	return inverted;
}

struct matrix *transpose(struct matrix *mat) {
	assert(mat);
	struct matrix *new_matrix = create_matrix(mat->n, mat->m);
	for (int row = 0; row < mat->m; row++) {
		for (int col = 0; col < mat->n; col++) {
			new_matrix->vals[col][row] = mat->vals[row][col];
		}
	}

	return new_matrix;
}

struct matrix *linear_reg(struct matrix *x, struct matrix *y) {
	assert(x->m == y->m);
	struct matrix *x_transposed = transpose(x);
	struct matrix *xTx = matrix_multiply(x_transposed, x);
	
	printf("xTx Matrix: \n");
	print_matrix(xTx);

	struct matrix *xTx_inverse = invert_matrix(xTx);

	printf("xTx Inverted: \n");
	print_matrix(xTx_inverse);

	struct matrix *xTy = matrix_multiply(x_transposed, y);

	printf("xTy Matrix: \n");
	print_matrix(xTy);

	struct matrix *coefficients = matrix_multiply(xTx_inverse, xTy);
	
	destroy_matrix(x_transposed);
	destroy_matrix(xTx);
	destroy_matrix(xTx_inverse);
	destroy_matrix(xTy);

	return coefficients;

}
