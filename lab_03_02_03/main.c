#include <stdio.h>
#include <stdlib.h>

#define OK 0

#define SCANF_CHECK 1

#define ARRAY_ERROR 1
#define SCANF_N_ERROR 2
#define SCANF_M_ERROR 3
#define SCANF_FUNC_ERROR 4

#define CHECK_FOR_VALUES_ERROR 5
#define N_VALUE_ERROR 6
#define M_VALUE_ERROR 7

#define NUMBER_ERROR 8
#define EXIST_ERROR 9

#define CHECK_TRUE 1
#define CHECK_FALSE 0

#define MAX_M 10
#define MAX_N 10
#define MIN_M 0
#define MIN_N 0

int input_array(int (*const arr)[MAX_M], int const n, int const m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (scanf("%d", &arr[i][j]) != SCANF_CHECK)
            {
                return ARRAY_ERROR;
            }
        }
    }
    return OK;
}

int check_availability_number(int element, int const number)
{
    if (element == number)
    {
        return CHECK_TRUE;
    }

    while (element != 0)
    {
        if (element % 10 == number)
        {
            return CHECK_TRUE;
        }

        element /= 10;
    }

    return CHECK_FALSE;
}

void delete_col(int (*const arr)[MAX_M], int const n, int *m, int const deleted_col)
{
    for (int j = deleted_col; j < *m - 1; j++)
    {
        for (int i = 0; i < n; i++)
        {
            arr[i][j] = arr[i][j + 1];
        }
    }
    (*m)--;
}

void print_matrix(int (*const arr)[MAX_M], int const n, int const m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", arr[i][j]);
        }

        printf("\n");
    }
}

int scanf_func(int *const n)
{
    if (scanf ("%d", n) != SCANF_CHECK)
    {
        return SCANF_FUNC_ERROR;
    }

    return OK;
}

int check_for_values(int const n)
{
    if (MIN_N >= n || n > MAX_N)
    {
        return CHECK_FOR_VALUES_ERROR;
    }

    return OK;
}

void make_matrix(int (*arr)[MAX_M], int n, int *m, int number)
{
    for (int j = 0; j < *m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (check_availability_number(abs(arr[i][j]), number))
            {
                delete_col(arr, n, m, j);
                j--;
                break;
            }
        }
    }
}

int main(void)
{
    int n;

    if (scanf_func(&n))
    {
        return SCANF_N_ERROR;
    }

    int m;

    if (scanf_func(&m))
    {
        return SCANF_M_ERROR;
    }

    if (check_for_values(n))
    {
        return N_VALUE_ERROR;
    }

    if (check_for_values(m))
    {
        return M_VALUE_ERROR;
    }

    int arr[MAX_N][MAX_M];

    if (input_array(arr, n, m))
    {
        printf("Inputted incorrect element of array");

        return ARRAY_ERROR;
    }

    int number;

    if (scanf_func(&number))
    {
        return SCANF_N_ERROR;
    }

    if (number > 9 || number < 0)
    {
        printf("number must be above zero and less then ten");
        return NUMBER_ERROR;
    }

    make_matrix(arr, n, &m, number);

    if (m < 1)
    {
        return EXIST_ERROR;
    }

    print_matrix(arr, n, m);

    return OK;
}
