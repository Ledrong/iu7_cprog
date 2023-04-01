#include <stdio.h>
#include <stdint.h>
#include <limits.h>

#define INP_ERROR 1
#define INP_OK 0

void print(uint32_t *a)
{
    printf("Result: ");

    for (int i = 31; i >= 0; i--)
    {
        printf("%d", (int)((*a & (1ULL << i)) >> i));
    }
}

int main(void)
{
    uint32_t a;

    if (scanf ("%ui ", &a) != 1)
    {
        printf("Error: Input error (a must be number) ");

        return INP_ERROR;
    }

    for (uint32_t i = 0; i < 32; i += 2)
    {   
        a = (a & ((1ULL << i) - 1)) + ((a & (1ULL << (i + 1))) >> 1) + ((a & (1ULL << i)) << 1) + 
            (a & (UINT_MAX - ((1ULL << (i + 2)) - 1)));
    }

    print(&a);

    return INP_OK;
}
