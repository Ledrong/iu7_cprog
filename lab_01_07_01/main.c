#include <stdio.h>
#include <math.h>

#define INP_ERROR_A_AND_E_MUST_BE_FLOAT 1
#define INP_ERROR_E_MUST_BE_BETWEEN_ZERO_AND_ONE 2
#define INP_OK 0

//Функция для рассчёта суммы ряда
double sum_of_math_serie(double x, double e)
{
    double s = 0, current_sum = x, current_chlen;
    int k = 1, denominator;

    while (fabs(current_sum) > e)
    {
        k += 2;
        denominator = (k - 1) * k;
        current_chlen = (pow(x, 2) * (-1)) / denominator;

        s += current_sum;
        current_sum *= current_chlen;
    }

    return s;
}

int main(void)
{
    double x, e;
    printf("Input x and e: ");

    if (scanf("%lf%lf", &x, &e) != 2)
    {
        printf("Inputted incorrect values, please input only numbers");

        return INP_ERROR_A_AND_E_MUST_BE_FLOAT;
    }

    if (0 > e || 1 < e)
    {
        printf("Inputted incorrect value of e; e must belong to interval (0,1]");

        return INP_ERROR_E_MUST_BE_BETWEEN_ZERO_AND_ONE;
    }

    //Точное значение (f)
    double certain_value;
    certain_value = sin(x);

    //Рассчёт суммы
    double sum;

    sum = sum_of_math_serie(x, e);

    double absolute_value, otnos_value;

    //Рассчёт нужных величин
    absolute_value = fabs(certain_value - sum);

    otnos_value = absolute_value / (fabs(certain_value));

    printf("approximate s = %lf\n"
        "exact f = %lf\n"
        "absolute delta = %lf\n"
        "relative delta = %lf\n"
        "", certain_value, sum, absolute_value, otnos_value);

    return INP_OK;
}

