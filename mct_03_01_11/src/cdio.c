#include "cdio.h"

double ***matrix_array(int n, int rows, int columns)
{
    double ***array, **ptrs, *data;

    array = malloc(n * sizeof(double**));
    if (!array)
        return NULL;

    for (int i = 0; i < n; i++)
    {
        ptrs = malloc(rows * sizeof(double*));
        if (!ptrs)
            return NULL;

        array[i] = ptrs;
    }

    data = malloc(rows * columns * sizeof(double));
    if (!data)
    {
        free(ptrs);

        return NULL;
    }

    for (int j = 0; j < rows; ++j)
        ptrs[j] = data + j * columns;

    return array;
}


void free_array(double ***array, int n)
{
    for (int i = 0; i < n; ++i)
    {
        free(array[i][0]);

        free(array[i]);
    }
    free(array);
}

int input_matrix(double ***array, int rows, int columns, int n)
{
    for (int k = 0; k < n; k++)
    {
        printf("Input i' matrix:\n");
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < columns; ++j)
            {
                double element = 0;

                if (scanf("%lf", &element) != 1)
                {
                    free_matrix(array);

                    return MATRIX_ELEMENT_ERROR;
                }

            array[k][i][j] = element;
            }
        }
    return EXIT_SUCCESS;
}

void print_matrix(double ***array, int n)
{
    for (k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            printf("%lf ", array[i]);
        }
    }
    printf("\n");
}

