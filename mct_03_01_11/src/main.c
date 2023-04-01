#include "cdio.h"
#include "functions.h"

int main(void)
{
    int n = 0;
    if (scanf("%d", &n) != 1)
        return N_ERRROR;

    int rows = 0, columns = 0;
    if (scanf("%d%d", &rows, &columns) != 2)
        return SIZE_ERRROR;

    double ***array;

    array = matrix_array(n, rows, columns);

    for (int i = 0; i < n; ++i)
        if (input_matrix(array, rows, columns, n))
            return MATRIX_ELEMENT_ERROR;

    sort_matrix(array, n, rows, columns);

    print_array(array, n);

    free_array(array, n);
    return EXIT_SUCCESS;
}