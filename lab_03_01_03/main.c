#include <stdio.h>

#define OK 0

#define ARRAY_ERROR 1

#define SCANF_CHECK 1
#define SCANF_N_ERROR 2
#define SCANF_M_ERROR 3
#define SCANF_FUNC_ERROR 4

#define CHECK_FOR_VALUES_ERROR 5
#define N_VALUE_ERROR 6
#define M_VALUE_ERROR 7

#define MAX_M 10
#define MAX_N 10

#define MIN_N 0
#define MIN_M 0

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

int check_monotonic_sequence(int (*const arr)[MAX_M], int const m, int const k)
{
    int check_element = 1;
    
    if (m == 1)
    {
        check_element = 0;
    }
	
    for (int j = 1; j < m - 1; j++)
    {
        if ((arr[k][j] < arr[k][j - 1] && arr[k][j + 1] > arr[k][j]) ||
            (arr[k][j] > arr[k][j - 1] && arr[k][j + 1] < arr[k][j]))
        {
            check_element = 0;
        }
    }
    return check_element;
}

void assignment_massive(int (*const arr)[MAX_M], int *const array, int const n, int const m)
{
    for (int i = 0; i < n; i++)
    {
        array[i] = 0;
        if (check_monotonic_sequence(arr, m, i))
        {
            array[i] = 1;
        }
    }
}

void print_array(int const *array, int const n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
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
    
    int array[MAX_N];

    assignment_massive(arr, array, n, m);
    print_array(array, n);

    return OK;
}
