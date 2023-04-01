#ifndef CDIO_H
#define CDIO_H

#define DATA_ERROR 1
#define SCANF_COMMAND_ERROR 2
#define COMMAND_ERROR 3
#define SCANF_COUNT_ERROR 4
#define COUNT_ERROR 5
#define SCANF_ELEM_ERROR 6
#define SCANF_A_ERROR 7

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "list.h"

int free_list(node_t *list, int count);
int input_command(char *command);
int create_push_new_node(node_t **list, int elem_data);
int input_list(int *count, node_t *my_list);
int free_list(node_t *list, int count);

#endif

