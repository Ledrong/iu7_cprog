#include "cdio.h"

int input_command(char *command)
{
    if (scanf("%s", command) != 1)
        return SCANF_COMMAND_ERROR;

    if (strcmp(command, "pop_front") != 0 && strcmp(command, "find") != 0 && \
        strcmp(command, "remove_duplicates") != 0 && strcmp(command, "sort") != 0)
        return COMMAND_ERROR;

    return EXIT_SUCCESS;
}

int create_push_new_node(node_t **list, int elem)
{
    node_t *tmp = malloc(sizeof(node_t));
    if (!tmp)
        return DATA_ERROR;

    node_t *cur_element = *list;

    while (cur_element->next != NULL)
    {
        cur_element = cur_element->next;
    }

    cur_element->next = tmp;
    tmp->next = NULL;

    return EXIT_SUCCESS;
}

int input_list(int *count, node_t *my_list)
{
    if (scanf("%d", count) != 1)
    {
        free(my_list);
        return SCANF_COUNT_ERROR;
    }

    if (*count <= 0)
    {
        free(my_list);
        return COUNT_ERROR;
    }

    int *elem_list = 0;

    for (int i = 0; i < *count; ++i)
    {
        if (scanf("%d", elem_list) != 1)
        {
            free_list(my_list, i);
            return SCANF_ELEM_ERROR;
        }

        if (i == 0)
        {
            my_list->data = elem_list;
        }
        else
        {
            create_push_new_node(&my_list, *elem_list);
        }
    }

    return EXIT_SUCCESS;
}

int free_list(node_t *list, int count)
{
    node_t *cur_element = list;
    for (int i = 0; i < count; ++i)
    {
        node_t *pointer = cur_element->next;
        free(cur_element);
        cur_element = pointer;
    }

    return EXIT_SUCCESS;
}
