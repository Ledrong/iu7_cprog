#include "polinom_math.h"

int val(polinom_t *polinom, int count, int *val_result)
{
    int a = 0;

    polinom_t *head = polinom;

    if (scanf("%d", &a) != 1)
        return SCANF_A_ERROR;

    for (int i = 0; i < count; ++i)
    {
        *val_result += polinom->ratio * pow(a, count - i - 1);
        polinom = polinom->next;
    }

    free_list(head, count);

    printf("%d", *val_result);

    return EXIT_SUCCESS;
}

void ddx(polinom_t *polinom, int count)
{
    polinom_t *head = polinom;

    for (int i = 0; i < count - 1; ++i)
    {
        printf("%d ", polinom->ratio * (count - i - 1));
        polinom = polinom->next;
    }

    printf("L");

    free_list(head, count);
}

void sum(polinom_t *polinom, polinom_t *polinom_second, int count, int count_second)
{
    polinom_t *head = polinom;
    polinom_t *head_second = polinom_second;

    int count_copy = count, count_second_copy = count_second;
    if (count < count_second)
    {
        for (int delta = count_second - count; delta != 0; delta--)
        {
            printf("%d ", polinom_second->ratio);
            polinom_second = polinom_second->next;
        }

        count_second = count;
    }

    if (count > count_second)
    {
        for (int delta = count - count_second; delta != 0; delta--)
        {
            printf("%d ", polinom->ratio);
            polinom = polinom->next;
        }

        count = count_second;
    }

    for (int i = 0; i < count; ++i)
    {
        printf("%d ", polinom->ratio + polinom_second->ratio);
        polinom_second = polinom_second->next;
        polinom = polinom->next;
    }

    printf("L");

    free_list(head, count_copy);
    free_list(head_second, count_second_copy);
}

void dvd(polinom_t *polinom, int count)
{
    polinom_t *head = polinom;

    for (int i = 0; i < count; ++i)
    {
        if (i % 2 != 0)
        {
            printf("%d ", polinom->ratio);
        }
        polinom = polinom->next;
    }
    printf("L\n");

    polinom = head;

    for (int i = 0; i < count; ++i)
    {
        if (i % 2 == 0)
        {
            printf("%d ", polinom->ratio);
        }

        polinom = polinom->next;
    }

    free_list(head, count);
    printf("L");
}
