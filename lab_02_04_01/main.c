#include <stdio.h>

#define OK 0

#define SCANF_CHECK 1

#define INPUT_ERROR 1


#define INCORRECT_N 2
#define N_NOT_IN_SCOPE 3

#define MIN_SIZE 0
#define MAX_SIZE 10

#define NOT_CRASH 100

int input_check_array(int *arr)
{
    int i = 0;

    while (scanf("%d", &arr[i]) == SCANF_CHECK)
    {
        i++;
    }
    return i;
}

void insertion_sort(int const n, int arr[])
{
    int element, position;
 
    for (int i = 1; i < n; i++)
    {
        element = arr[i];
        position = i - 1;

        while (position >= 0 && arr[position] > element)
        {
            arr[position + 1] = arr[position];
            position = position - 1;
        }
        arr[position + 1] = element;
    }
}

void print_array(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main(void)
{
    int arr[MAX_SIZE], n;
    n = input_check_array(arr);

    insertion_sort(n, arr);

    if (n > MAX_SIZE)
    {
        print_array(arr, MAX_SIZE);

        return NOT_CRASH;
    }

    if (n > MIN_SIZE && MAX_SIZE >= n)
    {
        print_array(arr, n);

        return OK;
    }

    if (n == 0)
    {
        return INPUT_ERROR;
    }

    return OK;
}
