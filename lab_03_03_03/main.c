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

#define MAX_M 10
#define MAX_N 10
#define MIN_N 0
#define MIN_M 0

int input_array(int (*const arr)[MAX_M + 1], int const n, int const m)
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

void change_position_of_elements(int (*const arr)[MAX_M + 1], int const n, int const m)
{
    for (int i = 0; i < n; i++)
    {
        int min = arr[i][0];
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] < min)
            {
                min = arr[i][j];
            }
        }
        arr[i][m] = min;
    }
}

void change_columnes(int (*const arr)[MAX_M + 1], int const s, int const m, int const i)
{
    int c;

    for (int j = 0; j <= m; j++)
    {
        c = arr[i][j];
        arr[i][j] = arr[s][j];
        arr[s][j] = c;
    }
}

void descending_smallest_elements(int (*const arr)[MAX_M + 1], int const n, int const m)
{
    change_position_of_elements(arr, n, m);

    for (int i = 0; i < n; i++)
    {
        for (int s = i + 1; s < n; s++)
        {
            if (arr[i][m] < arr[s][m])
            {
                change_columnes(arr, s, m, i);
            }
        }
    }
}

void print_matrix(int (*const arr)[MAX_M + 1], int const n, int const m)
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

    int arr[MAX_N][MAX_M + 1];

    if (input_array(arr, n, m))
    {
        printf("Inputted incorrect element of array");

        return ARRAY_ERROR;
    }

    descending_smallest_elements(arr, n, m);

    print_matrix(arr, n, m);

    return OK;
}
