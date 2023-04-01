#include "cdio.h"

int main(void)
{
    char command[100];

    int rc;

    rc = input_command(command);

    if (rc)
        return rc;


    node_t *my_list = malloc(sizeof(node_t));
    my_list->next = NULL;

    free(my_list);

    if (rc)
        return rc;

    if (strcmp(command, "pop_front") == 0)
    {
        pop_front(&my_list);
    }

    if (strcmp(command, "remove_duplicates") == 0)
    {
        remove_duplicates(&my_list, comparator);
    }

    return EXIT_SUCCESS;
}
