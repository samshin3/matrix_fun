#include "matrix.h"

int main(void) {
    int m = 0;
    int n = 0;

    scanf("%d", &m);
    scanf("%d", &n);
    struct matrix * m1 = create_matrix(m, n);
    fill_matrix(m1);

    scanf("%d", &m);
    scanf("%d", &n);    
    struct matrix *m2 = create_matrix(m, n);
    fill_matrix(m2);

    print_matrix(m1);
    print_matrix(m2);

    struct matrix *product = linear_reg(m1, m2);
    print_matrix(product);

    destroy_matrix(m1);
    destroy_matrix(m2);
    destroy_matrix(product);
}
