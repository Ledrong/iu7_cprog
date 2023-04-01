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

#define N_AND_M_ARE_DIFFERENT 8

#define MAX_M 10
#define MAX_N 10
#define MIN_N 0
#define MIN_M 0

void filling_matrix(int (*const arr)[MAX_M], int const n)
{
    int k = 1, r = 0, l = n * n + 1;

    while (k != l)
    {
        for (int i = r; (i <= n - r - 1) && k != n * n + 1; i++)
        {
            arr[i][r] = k;
            k++;
        }

        for (int i = r + 1; (i <= n - r - 2) && k != n * n + 1; i++)
        {
            arr[n - r - 1][i] = k;
            k++;
        }

        for (int i = n - r - 1; (i >= r) && k != n * n + 1; i--)
        {
            arr[i][n - r - 1] = k;
            k++;
        }

        for (int i = n - r - 2; (i >= r + 1) && k != n * n + 1; i--)
        {
            arr[r][i] = k;
            k++;
        }

        r++;
    }
}

void print_matrix(int (*const arr)[MAX_M], int const n)
{
    for (int i = 0; i < n; i++)
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

int check_for_values(int n)
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
        return N_AND_M_ARE_DIFFERENT;
    }

    int arr[MAX_N][MAX_M];

    filling_matrix(arr, n);

    print_matrix(arr, n);

    return OK;
}
