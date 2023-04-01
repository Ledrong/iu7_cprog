#include <stdio.h>
#include <math.h>

#define INP_ERROR_VALUES_ARE_NOT_INTEGER 1
#define INP_ERROR_A_MUST_BE_ABOVE_ZERO 2
#define INP_ERROR_D_MUST_BE_ABOVE_ZERO 3
#define INP_OK 0

int remainder_quotient(int a, int const d)
{
    int q = 0;

    while (0 <= a - d)
    {
        a -= d;
        q++;
    }

    return q;
}

int main(void)
{
    int a, d;
    printf("Input a and d: ");

    if (scanf ("%d%d", &a, &d) != 2)
    {
        printf("Inputted incorrect values, please input integer number");

        return INP_ERROR_VALUES_ARE_NOT_INTEGER;
    }

    if (0 >= d)
    {
        printf("Inputted incorrect values (d must be > 0)");

        return INP_ERROR_D_MUST_BE_ABOVE_ZERO;
    }

    if (0 >= a)
    {
        printf("Inputted incorrect values (d must be > 0)");

        return INP_ERROR_A_MUST_BE_ABOVE_ZERO;
    }

    int r, q = 0, a1 = a;

    q = remainder_quotient(a, d);
    // Рассчёт остатка от деления
    r = a1 - q * d;

    printf("q = %d\n", q);
    printf("r = %d\n", r);
   
    return INP_OK;
}
