#include "math_functions.h"
#include "cdio.h"

int sum_matrixes(double **matrix_a, double **matrix_b, double **result_matrix, int rows_a, int columns_a, int rows_b, int columns_b)
{
    if (rows_a != rows_b || columns_a != columns_b)
        return DIFFERENT_SIZE_ERROR;

    for (int i = 0; i < rows_a; ++i)
        for (int j = 0; j < columns_a; ++j)
            result_matrix[i][j] = matrix_a[i][j] + matrix_b[i][j];

    return EXIT_SUCCESS;
}

int multiply_matrixes(double **matrix_a, double **matrix_b, double **result_matrix, int rows_a, int columns_a, int rows_b, int columns_b)
{
    if (columns_a != rows_b)
        return DIFFERENT_SIZE_ERROR;

    for (int i = 0; i < rows_a; i++)
    {
        for (int j = 0; j < columns_b; j++)
        {
            result_matrix[i][j] = 0.0;

            for (int k = 0; k < rows_b; k++)
            {
                result_matrix[i][j] += matrix_a[i][k] * matrix_b[k][j];
            }
        }
    }

    return EXIT_SUCCESS;
}

void del_row_column(double **matrix, int rows, int columns, int row, int column, double **res_matrix)
{
    int stepr = 0, stepc = 0;
    for (int i = 0; i < rows - 1; i++)
    {
        if (i == row)
        {
            stepr = 1;
        }

        stepc = 0;
        for (int j = 0; j < columns - 1; j++)
        {
            if (j == column)
            {
                stepc = 1;
            }

            res_matrix[i][j] = matrix[i + stepr][j + stepc];
        }
    }
}


double count_determinant(double **matrix, int rows_a, int columns_a)
{
    double det = 0.0;
    int degree = 1;

    if (rows_a == 1)
        return matrix[0][0];
    else if (rows_a == 2)
        return (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]);
    else
    {
        double **matrix_copy;
        matrix_copy = allocate_matrix(rows_a - 1, columns_a - 1);

        for (int j = 0; j < columns_a; j++)
        {
            del_row_column(matrix, rows_a, columns_a, 0, j, matrix_copy);

            det += degree * matrix[0][j] * count_determinant(matrix_copy, rows_a - 1, columns_a - 1);
            degree = -degree;
        }

        free_matrix(matrix_copy);
    }

    return det;
}
