#include "polinom_math.h"

int main(void)
{
    char command[100];

    int rc;

    rc = input_command(command);

    if (rc)
        return rc;

    int count;

    polinom_t *polinom = malloc(sizeof(polinom_t));
    if (!polinom)
        return DATA_ERROR;

    polinom->next = NULL;

    rc = input_polinom(&count, polinom);

    if (rc)
        return rc;

    if (strcmp(command, "val") == 0)
    {
        int val_result = 0;

        rc = val(polinom, count, &val_result);
        if (rc)
        {
            free_list(polinom, count);
            return rc;
        }
    }

    if (strcmp(command, "ddx") == 0)
        ddx(polinom, count);

    if (strcmp(command, "sum") == 0)
    {
        int count_second;
        polinom_t *polinom_second = malloc(sizeof(polinom_t));
        if (!polinom_second)
        {
            free_list(polinom, count);
            return DATA_ERROR;
        }

        polinom_second->next = NULL;

        rc = input_polinom(&count_second, polinom_second);
        if (rc)
        {
            free_list(polinom, count);
            return rc;
        }

        sum(polinom, polinom_second, count, count_second);
    }

    if (strcmp(command, "dvd") == 0)
        dvd(polinom, count);

    return EXIT_SUCCESS;
}
