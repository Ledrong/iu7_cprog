#include <stdio.h>
#include <math.h>

#define INP_ERROR_X_MUST_BE_FLOAT 1
#define INP_ERROR_X_MUST_BE_ABOVE_ZERO 2
#define INP_OK 0
#define X_ERROR 1

float sum(float x)
{
    int k = 1, x_copy = x;
    float sum = 1;

    if (0 > x_copy)
    {
        printf("Inputted incorrect value of x, x must be >= 0");

        return INP_ERROR_X_MUST_BE_ABOVE_ZERO;
    }

    while (0 <= x)
    {
        sum = sum / (x + k);
        k++;

        if (scanf ("%f", &x) != 1)
        {
            printf("Inputted incorrect value of x, please input only numbers");

            return INP_ERROR_X_MUST_BE_FLOAT;
        }
    }

    return sum;
}

int main()
{
    float x;

    if (scanf("%f", &x) != 1)
    {
        printf("Inputted incorrect value of x, please input only numbers");

        return INP_ERROR_X_MUST_BE_FLOAT;
    }

    float g;
    g = sum(x);

    if (g == INP_ERROR_X_MUST_BE_ABOVE_ZERO || g == INP_ERROR_X_MUST_BE_FLOAT)
        return X_ERROR;

    g = exp(g);
    printf("g = %f", g);

    return INP_OK;
}
