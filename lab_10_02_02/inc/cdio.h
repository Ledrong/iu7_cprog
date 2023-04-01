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

typedef struct polinom polinom_t;

struct polinom
{
    int ratio;
    polinom_t *next;
};

int free_list(polinom_t *list, int count);
int create_push_new_node(polinom_t **list, int ratio);
int input_command(char *command);
int input_polinom(int *count, polinom_t *polinom);

#endif
