#include <stdio.h>
#include <math.h>

#define DEGREETORADIANS M_PI / 180
#define OK 0

int main(void)
{
    float a, b, fi;
    scanf ("%f%f%f", &a, &b, &fi);

    float s;
    s = 0.5 * a * b * sinf(fi * DEGREETORADIANS);
    printf("%f", s);

    return OK;
}
