#include "matrix.h"
#include <stdio.h>

int main(void) {
	int rows;
	int cols;

	// read matrix shape
	scanf("%d", &rows);
	scanf("%d", &cols);

	struct matrix *m1 = create_matrix(rows, cols);
	fill_matrix(m1);

	scanf("%d", &rows);
	scanf("%d", &cols);

	struct matrix *m2 = create_matrix(rows, cols);
	fill_matrix(m2);	

	print_matrix(m1);
	print_matrix(m2);

	struct matrix *value_vector = linear_reg(m1, m2);
	print_matrix(value_vector);

	destroy_matrix(m1);
	destroy_matrix(m2);
	destroy_matrix(value_vector);
}
