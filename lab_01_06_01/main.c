#include <stdio.h>
#include <math.h>

#define EPS 1e-10
#define INP_ERROR_XA_AND_YA_MUST_BE_FLOAT 1
#define INP_ERROR_XB_AND_YB_MUST_BE_FLOAT 2
#define INP_ERROR_XC_AND_YC_MUST_BE_FLOAT 3
#define ERROR_TRIANGLE_DOES_NOT_EXIST 4
#define INP_OK 0

float skew_product(float xa, float ya, float xb, float yb, float xc, float yc)
{
    return fabsf((xb - xa) * (yc - ya) - (xc - xa) * (yb - ya));
}

int main(void)
{
    float xa, ya;
    for (int i = 1; i < 4; i++)
        printf("Input x%d, y%d: ", i, i);

    if (scanf ("%f%f", &xa, &ya) != 2)
    {
        printf("Incorrect values of vertex a");

        return INP_ERROR_XA_AND_YA_MUST_BE_FLOAT;
    }

    float xb, yb;

    if (scanf ("%f%f", &xb, &yb) != 2)
    {
        printf("Incorrect values of vertex b");

        return INP_ERROR_XB_AND_YB_MUST_BE_FLOAT;
    }

    float xc, yc;

    if (scanf ("%f%f", &xc, &yc) != 2)
    {
        printf("Incorrect values of vertex c");

        return INP_ERROR_XC_AND_YC_MUST_BE_FLOAT;
    }

    float skew;

    // Рассчёт косого произведения двух векторов, принадлежащих треугольнику
    skew = skew_product(xa, ya, xb, yb, xc, yc);

    // Если косое произв-е = 0 то векторы коллинеарны => треугольника не существует

    if (skew < EPS)
    {
        printf("This triangle can't exist");

        return ERROR_TRIANGLE_DOES_NOT_EXIST;
    }

    float square;

    // Рассчёт площади треугольника
    square = skew / 2;
    printf("Square of the triangle = %.6g", square);

    return INP_OK;
}
