#include <stdio.h>

#define OK 0

#define SCANF_CHECK 1

#define ARRAY_ERROR 1
#define SCANF_N_ERROR 2
#define SCANF_M_ERROR 3
#define SCANF_FUNC_ERROR 4

#define CHECK_FOR_VALUES_ERROR 5
#define N_VALUE_ERROR 6
#define M_VALUE_ERROR 7
#define DIFFERENT_N_AND_M 8

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

void change_elements(int (*const arr)[MAX_M], int const n)
{
    for (int j = 0; j < n / 2; j++)
    {
        for (int i = j; i < n - j; i++)
        {
            int t = arr[i][j];
            arr[i][j] = arr[i][n - j - 1];
            arr[i][n - j - 1] = t;
        }
    }
}

void print_matrix(int (*const arr)[MAX_M], int const n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }

        printf("\n");
    }
}

int scanf_func(int *const n)
{
    if (scanf("%d", n) != SCANF_CHECK)
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

int main(void)
{
    int n;

    if (scanf_func(&n))
    {
        return SCANF_N_ERROR;
    }

    if (check_for_values(n))
    {
        return N_VALUE_ERROR;
    }

    int m;

    if (scanf_func(&m))
    {
        return SCANF_M_ERROR;
    }

    if (check_for_values(m))
    {
        return M_VALUE_ERROR;
    }

    if (n != m)
    {
        printf("N and M are different");

        return DIFFERENT_N_AND_M;
    }

    int arr[MAX_N][MAX_M];

    if (input_array(arr, n, m))
    {
        printf("Inputted incorrect element of array");

        return ARRAY_ERROR;
    }

    change_elements(arr, n);

    print_matrix(arr, n);

    return OK;
}
