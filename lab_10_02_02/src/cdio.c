#include "cdio.h"

int free_list(polinom_t *list, int count)
{
    polinom_t *cur_element = list;

    for (int i = 0; i < count; ++i)
    {
        polinom_t *pointer = cur_element->next;

        free(cur_element);
        cur_element = pointer;
    }

    return EXIT_SUCCESS;
}

int create_push_new_node(polinom_t **list, int ratio)
{
    polinom_t *tmp = malloc(sizeof(polinom_t));
    if (!tmp)
        return DATA_ERROR;

    polinom_t *cur_element = *list;

    while (cur_element->next != NULL)
    {
        cur_element = cur_element->next;
    }

    tmp->ratio = ratio;

    cur_element->next = tmp;
    tmp->next = NULL;

    return EXIT_SUCCESS;
}

int input_command(char *command)
{
    if (scanf("%s", command) != 1)
        return SCANF_COMMAND_ERROR;

    if (strcmp(command, "val") != 0 && strcmp(command, "ddx") != 0 && \
        strcmp(command, "sum") != 0 && strcmp(command, "dvd") != 0)
        return COMMAND_ERROR;

    return EXIT_SUCCESS;
}

int input_polinom(int *count, polinom_t *polinom)
{
    if (scanf("%d", count) != 1)
    {
        free(polinom);
        return SCANF_COUNT_ERROR;
    }

    if (*count <= 0)
    {
        free(polinom);
        return COUNT_ERROR;
    }

    int elem_list = 0;

    for (int i = 0; i < *count; ++i)
    {
        if (scanf("%d", &elem_list) != 1)
        {
            free_list(polinom, i);
            return SCANF_ELEM_ERROR;
        }

        if (i == 0)
        {
            polinom->ratio = elem_list;
        }
        else
        {
            create_push_new_node(&polinom, elem_list);
        }
    }

    return EXIT_SUCCESS;
}

