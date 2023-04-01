#include "multiplication.h"

void make_ones_matrix(int *matrix, int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            matrix[i * cols + j] = (i == j ? 1 : 0);
}

void multiply_matrixes(int *matrix_a, int *matrix_b, int *result_matrix, int rows_a, int columns_a)
{
    for (int i = 0; i < rows_a; i++)
    {
        for (int j = 0; j < columns_a; j++)
        {
            int sum = 0;

            for (int k = 0; k < columns_a; k++)
            {
                sum += matrix_a[i * rows_a + k] * matrix_b[k * rows_a + j];
            }
            result_matrix[i * rows_a + j] = sum;
        }
    }
}
