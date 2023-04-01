#include <stdio.h>
#include <math.h>

#define OK 0

int main(void)
{
    int a;
    scanf("%d", &a);

    int pr = 1;
    a = fabs(a);

    int k;
    for (int i = 0; i < 3; i++)
    {
        k = a % 10;
        a = a / 10;
        pr *= k;
    }

    printf("%d", pr);

    return OK;
}
