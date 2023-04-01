#include <stdio.h>
#include <math.h>

#define OK 0

int main(void)
{
    float vo, a, t;
    scanf ("%f%f%f", &vo, &a, &t);

    float s;
    s = vo * t + a * t * t / 2;
    printf("%.6f\n", s);

    return OK;
}
