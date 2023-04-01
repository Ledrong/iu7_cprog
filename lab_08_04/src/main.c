#include "functions.h"
#include "multiplication.h"
#include "error_codes.h"
#include "cdio.h"

int main(void)
{
    printf("Введите m, n через пробел: ");

    int m, n;
    if (scanf("%d%d", &m, &n) != 2)
    {
        printf("В качестве m и n вводятся только целые числа\n");

        return SCANF_ERROR;
    }

    int *matrix_a;
    matrix_a = NULL;

    printf("Введите матрицу а: ");

    if (input_matrix(&matrix_a, m, n))
        return INPUT_MATRIX_ERROR;

    printf("Введите p, q через пробел: ");

    int p, q;
    if (scanf("%d%d", &p, &q) != 2)
    {
        printf("В качестве p и q вводятся только целые числа\n");
        free(matrix_a);
        return SCANF_ERROR;
    }

    printf("Введите матрицу b: ");

    int *matrix_b;
    matrix_b = NULL;

    if (input_matrix(&matrix_b, p, q))
    {
        free(matrix_a);
        return INPUT_MATRIX_ERROR;
    }

    make_square_matrix(&matrix_a, &m, &n);
    make_square_matrix(&matrix_b, &p, &q);

    if (m > p)
    {
        add_row_matrix(&matrix_b, &p, q, m);

        add_columns_matrix(&matrix_b, p, &q, n);
    }
    else if (m < p)
    {
        add_row_matrix(&matrix_a, &m, n, p);

        add_columns_matrix(&matrix_a, m, &n, q);
    }

    printf("Введите ro и gamma через пробел: ");

    int ro, gamma;

    if (scanf("%d%d", &ro, &gamma) != 2)
    {
        printf("В качестве ro и gamma вводятся только целые числа\n");
        free(matrix_a);
        free(matrix_b);
        return SCANF_ERROR;
    }

    if (ro < 0 || gamma < 0)
    {
        printf("ro и gamma должны быть неотрицательными");
        free(matrix_a);
        free(matrix_b);
        return ERROR_SIZE_ZERO;
    }

    int *matrix_a_degree;
    matrix_a_degree = malloc(m * n * sizeof(int));
    make_ones_matrix(matrix_a_degree, m, n);

    int *matrix_result_a_tmp = malloc(m * n * sizeof(int));
    for (int i = 0; i < ro; i++)
    {
        multiply_matrixes(matrix_a, matrix_a_degree, matrix_result_a_tmp, m, n);
        copy_square_matrix(matrix_result_a_tmp, matrix_a_degree, m, n);
    }
    free(matrix_result_a_tmp);
    free(matrix_a);

    int *matrix_b_degree;
    matrix_b_degree = malloc(p * q * sizeof(int));
    make_ones_matrix(matrix_b_degree, p, q);

    int *matrix_result_b_tmp = malloc(p * q * sizeof(int));
    for (int i = 0; i < gamma; i++)
    {
        multiply_matrixes(matrix_b, matrix_b_degree, matrix_result_b_tmp, p, q);
        copy_square_matrix(matrix_result_b_tmp, matrix_b_degree, p, q);
    }
    free(matrix_result_b_tmp);
    free(matrix_b);

    int *matrix_result;
    matrix_result = malloc(p * q * sizeof(int));

    multiply_matrixes(matrix_a_degree, matrix_b_degree, matrix_result, m, q);

    free(matrix_a_degree);
    free(matrix_b_degree);

    print_matrix(matrix_result, m, q);
    free(matrix_result);

    return EXIT_SUCCESS;
}
