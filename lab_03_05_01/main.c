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

#define EXIST_ERROR 8

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

int sum_element(int element)
{
    int sum = 0;

    while (element > 0)
    {
        sum += element % 10;
        element /= 10;
    }

    return sum;
}

void array_shift(int *const array, int  const n, int const amount_for_shift)
{
    for (int l = 0; l < amount_for_shift; l++)
    {
        int k = array[0];

        for (int i = 1; i < n; i++)
        {
            array[i - 1] = array[i];
        }

        array[n - 1] = k;
    }
}

void get_massive(int (*const arr)[MAX_M], int const n, int const m, int *z, int *array)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (sum_element(abs(arr[i][j])) > 10)
            {
                array[(*z)++] = arr[i][j];
            }
        }
    }
}

void send_massive(int (*const arr)[MAX_M], int const n, int const m, int *z, int *array)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (sum_element(abs(arr[i][j])) > 10)
            {
                arr[i][j] = array[(*z)++];
            }
        }
    }
}

int insert(int (*const arr)[MAX_M], int const n, int const m)
{
    int array[MAX_N * MAX_M];
    int z = 0;

    get_massive(arr, n, m, &z, array);

    if (z == 0)
    {
        return ARRAY_ERROR;
    }

    array_shift(array, z, 3);

    z = 0;

    send_massive(arr, n, m, &z, array);

    return OK;
}

int scanf_func(int *const n)
{
    if (scanf("%d", n) != SCANF_CHECK)
    {
        return SCANF_FUNC_ERROR;
    }

    return OK;
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

    int arr[MAX_N][MAX_M];

    if (input_array(arr, n, m))
    {
        printf("Inputted incorrect element of array");

        return ARRAY_ERROR;
    }
    
    if (insert(arr, n, m))
    {
        printf("There are not needed elements");

        return EXIST_ERROR;
    }

    print_matrix(arr, n, m);

    return OK;
}
