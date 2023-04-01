#include "functions.h"

void find_max_element(int *matrix, int rows, int columns, int *i_max, int *j_max)
{
    int max_element = matrix[0];
    for (int j = 0; j < columns; j++)
        for (int i = 0; i < rows; i++)
            if (matrix[i * columns + j] >= max_element)
            {
                max_element = matrix[i * columns + j];
                *i_max = i;
                *j_max = j;
            }
}

int delete_row_matrix(int **matrix, int *rows, int columns, int i_del)
{
    int *matrix_copy;
    matrix_copy = malloc((*rows - 1) * columns * sizeof(int));

    for (int i = 0; i < *rows; i++)
        for (int j = 0; j < columns; j++)
        {
            if (i_del < i)
                matrix_copy[(i - 1) * columns + j] = (*matrix)[i * columns + j];
            else if (i_del > i)
                matrix_copy[i * columns + j] = (*matrix)[i * columns + j];
        }

    (*rows)--;
    free(*matrix);
    *matrix = matrix_copy;

    return EXIT_SUCCESS;
}

int delete_column_matrix(int **matrix, int rows, int *columns, int j_del)
{
    int *matrix_copy;
    matrix_copy = malloc(rows * (*columns - 1) * sizeof(int));

    for (int j = 0; j < *columns; j++)
        for (int i = 0; i < rows; i++)
        {
            if (j_del < j)
                matrix_copy[i * (*columns - 1) + j - 1] = (*matrix)[i * (*columns) + j];
            else if (j_del > j)
                matrix_copy[i * (*columns - 1) + j] = (*matrix)[i * (*columns) + j];
        }

    (*columns)--;
    free(*matrix);
    *matrix = matrix_copy;

    return EXIT_SUCCESS;
}

void make_square_matrix(int **matrix, int *rows, int *columns)
{
    while (*rows != *columns)
    {
        if (*rows > *columns)
        {
            int i_max, j_max;
            find_max_element(*matrix, *rows, *columns, &i_max, &j_max);
            delete_row_matrix(matrix, rows, *columns, i_max);
        }
        else
        {
            int i_max, j_max;
            find_max_element(*matrix, *rows, *columns, &i_max, &j_max);
            delete_column_matrix(matrix, *rows, columns, j_max);
        }
    }
}

void find_min_in_row(int *matrix, int rows, int columns, int *min_i, int *min_j)
{
    int min = matrix[0];
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            if (matrix[i * columns + j] <= min)
            {
                min = matrix[i * columns + j];
                *min_i = i;
                *min_j = j;
            }
}

void add_row_matrix(int **matrix, int *rows, int columns, int rows_needed)
{
    int *matrix_copy, sum = 0;

    while (*rows != rows_needed)
    {
        matrix_copy = malloc((*rows + 1) * columns * sizeof(int));

        for (int i = 0; i < *rows; i++)
        {
            for (int j = 0; j < columns; j++)
                matrix_copy[i * columns + j] = (*matrix)[i * columns + j];
        }

        for (int j = 0; j < columns; j++)
        {
            for (int i = 0; i < *rows; i++)
            {
                sum += matrix_copy[i * columns + j];
            }
            matrix_copy[*rows * columns + j] = floor((double)sum / (*rows));
            sum = 0;
        }
        (*rows)++;
        free(*matrix);
        *matrix = matrix_copy;
    }
}

void add_columns_matrix(int **matrix, int rows, int *columns, int columns_needed)
{
    int *matrix_copy;
    matrix_copy = malloc(rows * columns_needed * sizeof(int));

    int min;

    int amount_it = columns_needed - *columns;
    for (int k = 0; k < amount_it; ++k)
    {
        for (int i = 0; i < rows; i++)
        {
            min = (*matrix)[i * (*columns - k) + 0];
            for (int j = 0; j < *columns - k; j++)
            {
                matrix_copy[i * (columns_needed) + j] = (*matrix)[i * ((*columns) - k) + j];
                if ((*matrix)[i * ((*columns) - k) + j] < min)
                    min = (*matrix)[i * ((*columns) - k) + j];
            }
            matrix_copy[i * (columns_needed) + *columns] = min;
        }

        (*columns)++;
    }

    free(*matrix);
    *matrix = matrix_copy;
}

void copy_square_matrix(int *matrix_src, int *matrix_dst, int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            matrix_dst[i * cols + j] = matrix_src[i * cols + j];
}

