#include <stdio.h>

#define OK 0

#define SCANF_CHECK 1

#define FALSE 0
#define TRUE 1

#define ERROR_ARR 1
#define N_NOT_IN_SCOPE 2
#define EMPTY_ARRAYS 3

#define MIN_SIZE 1
#define MAX_SIZE 10

int unique_member(int *x, int *y)
{
    if (x == NULL || y == NULL)
    {
        return EMPTY_ARRAYS;
    }

    int count = 0, check_unique;
    
    for (int *pos_x = x; pos_x < y; pos_x++)
    {
        check_unique = TRUE;

        for (int *pos_y = x; pos_y < pos_x; pos_y++)
        {
            if (*pos_x == *pos_y)
            {
                check_unique = FALSE;
            }
        }

        if (check_unique)
        {
            count++;
        }
    }

    return count;
}

int check_array(int *pa, int *pe, int *rc)
{
    while (pa < pe)
    {
        *rc += scanf("%d", pa);
        pa++;
    }
    return *rc;
}

int main(void)
{
    int n;

    if (scanf("%i", &n) != SCANF_CHECK)
        return ERROR_ARR;

    if (MIN_SIZE > n || n > MAX_SIZE)
        return N_NOT_IN_SCOPE;

    int arr[MAX_SIZE], *pa = arr, *pe = arr + n;

    int rc = 0;

    check_array(pa, pe, &rc);
    
    if (rc != n)
    {
        return ERROR_ARR;
    }

    printf("%d ", unique_member(pa, pe));

    return OK;
}

