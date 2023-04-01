#include <stdio.h>

#define OK 0

#define SCANF_CHECK 1

#define INPUT_ERROR 2


#define POS_EXIST 3
#define INCORRECT_N 4
#define N_NOT_IN_SCOPE 5

#define MIN_SIZE 0
#define MAX_SIZE 10
#define MAX_COPY_SIZE 20

int input_check_array(int *arr, int const count)
{
    for (int i = 0; i < count; i++)
    {
        if (scanf("%d", &arr[i]) != SCANF_CHECK)
        {
            return INPUT_ERROR;
        }
    }

    return OK;
}

int positive_reverse(int element)
{
    int number_reverse = 0;

    while (element > 0) 
    {
        number_reverse = number_reverse * 10 + element % 10;
        element /= 10;
    }

    return number_reverse;
}

int insert(int *arr, int *k)
{
    for (int i = 0; i < MAX_COPY_SIZE; i++)
    {
        if (arr[i] > 0)
        {
            for (int d = MAX_COPY_SIZE - 1; d > i + 1; d--)
                arr[d] = arr[d - 1];
            arr[i + 1] = positive_reverse(arr[i]);
            i++;
            (*k)++;
        }
    }

    return OK;
}

void print_array(int *arr, const int n, const int k)
{
    for (int i = 0; i < n + k; i++)
        printf("%d ", arr[i]);
}

int main(void)
{
    int n;

    if (scanf("%d", &n) != SCANF_CHECK)
    {
        printf("You can input only integer numbers as N.");

        return INCORRECT_N;
    }

    if (MIN_SIZE >= n || n > MAX_SIZE)
    {
        printf("N must be more than zero and less than ten");

        return N_NOT_IN_SCOPE;
    }

    int arr[MAX_COPY_SIZE] = { 0 };

    if (input_check_array(arr, n))
    {
        printf("Inputted incorect array");

        return INPUT_ERROR;
    }
    int k = 0;

    if (insert(arr, &k))
        return POS_EXIST;

    print_array(arr, n, k);

    return OK;
}
