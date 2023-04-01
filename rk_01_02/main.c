#include <stdio.h>

#define OK 0
#define INCORRECT_N 1

int reverse(int element)
{
    int number_reverse = 0;

    while (element > 0) 
    {
        number_reverse = number_reverse * 10 + element % 10;
        element /= 10;
    }

    return number_reverse;
}

void print(int k)
{
    printf("reverse = %d", k);
}

int main(void)
{
    int n;

    if (scanf("%d", &n) != 1)
    {
        printf("You can input only integer numbers as n.");
        return INCORRECT_N;
    }

    int k;
    k = reverse(n);

    print(k);

    return OK;
}