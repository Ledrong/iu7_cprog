#include "cdio.h"

double **allocate_matrix(int rows, int columns)
{
    double **ptrs, *data;

    ptrs = malloc(rows * sizeof(double*));
    if (!ptrs)
        return NULL;

    data = malloc(rows * columns * sizeof(double));
    if (!data)
    {
        free(ptrs);

        return NULL;
    }

    for (int i = 0; i < rows; i++)
        ptrs[i] = data + i * columns;

    return ptrs;
}

void free_matrix(double **ptrs)
{
    free(ptrs[0]);

    free(ptrs);
}

int input_matrix(double **matrix, FILE *f, int *rows, int *columns)
{
    for (int i = 0; i < *rows; ++i)
        for (int j = 0; j < *columns; ++j)
        {
            double element = 0;
            if (fscanf(f, "%lf", &element) != 1)
            {
                free_matrix(matrix);

                return MATRIX_ELEMENT_ERROR;
            }

            matrix[i][j] = element;
        }

    return EXIT_SUCCESS;
}

void print_matrix(double **matrix, FILE *f, int rows, int columns)
{
    fprintf(f, "%d %d\n", rows, columns);
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            fprintf(f, "%lf ", matrix[i][j]);
        }
        fprintf(f, "\n");
    }
}
