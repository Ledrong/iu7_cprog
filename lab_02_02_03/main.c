#include <stdio.h>
#include <math.h>

#define OK 0

#define SCANF_CHECK 1

#define INPUT_ERROR 1

#define ARMSTRONG_NUMBERS_EXIST_ERROR 2
#define INCORRECT_N 3
#define N_NOT_IN_SCOPE 4

#define MAX_SIZE 10
#define MIN_SIZE 0

int input_check_array(int *arr, int const count)
{
    for (int i = 0; i < count; i++)
    {
        if (scanf ("%d", &arr[i]) != SCANF_CHECK)
        {
            return INPUT_ERROR;
        }
    }

    return OK;
}

int count_of_numerals(int element)
{
    int k = 0;

    while (element > 0) 
    {
        k++;
        element /= 10;
    }

    return k;
}

int armstrong_numbers(int element, int const k)
{
    int sum = 0, copy_element = element;

    while (element > 0) 
    {
        int digit = element % 10;

        int prod = 1;

        for (int i = 0; i < k; i++)
        {
            prod *= digit;
        }

        sum += prod;
        element /= 10;
    }

    return sum == copy_element;
}

void print_array(int *arr, int const n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            printf("%d ", arr[i]);
        }
    }
}

int amount_armstrong(int *arr, int *arr2, const int n)
{
    int k, amount = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            k = count_of_numerals(arr[i]);

            if (armstrong_numbers(arr[i], k))
            {
                arr2[i] = arr[i];
                amount++;
            }
        }
    }
    return amount;
}

int main(void)
{
    int n;

    if (scanf ("%d", &n) != SCANF_CHECK)
    {
        printf("You can input only integer numbers as n.");

        return INCORRECT_N;
    }

    if (MIN_SIZE >= n || n > MAX_SIZE)
    {
        printf("N must be more than zero and less than ten");

        return N_NOT_IN_SCOPE;
    }

    int arr[MAX_SIZE], arr2[MAX_SIZE] = { -1 };

    if (input_check_array(arr, n))
    {
        printf("Inputted incorect array");

        return INPUT_ERROR;
    }

    if (amount_armstrong(arr, arr2, n) == 0)
    {
        printf("There are no amrmstorng numbers in array");

        return ARMSTRONG_NUMBERS_EXIST_ERROR;
    }

    print_array(arr2, MAX_SIZE);

    return OK;
}
