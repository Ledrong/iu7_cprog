#include <stdio.h>
#include <math.h>

#define OK 0

#define MIN_SIZE 0

#define SCANF_CHECK 1

#define INPUT_ERROR 2
#define INCORRECT_N 3
#define N_NOT_IN_SCOPE 4

#define EXIST_ERROR 5
#define EXIST_ERROR_NEW 6

#define MAX_SIZE 10

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

float geometric_product(int *arr, int const count, double *averenge_prod)
{
    int k = 0, product = 1;

    for (int i = 0; i < count; i++)
    {
        if (arr[i] > 0)
        {
            product *= arr[i];
            k++;
        }
    }

    if (k == 0)
    {
        printf("Positive elements don't exist");

        return EXIST_ERROR;
    }

    *averenge_prod = pow(product, 1.0 / k);

    return OK;
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
        printf("N must be more, than zero and less, than eleven");

        return N_NOT_IN_SCOPE;
    }

    int arr[MAX_SIZE];

    if (input_check_array(arr, n))
    {
        printf("Inputted incorect array");
	    
        return INPUT_ERROR;
    }

    double average_product;

    if (geometric_product(arr, n, &average_product))
    {
        return EXIST_ERROR_NEW;
    }

    printf("%lf", average_product);

    return OK;
}
