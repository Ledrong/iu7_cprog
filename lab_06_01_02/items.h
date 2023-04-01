#ifndef ITEMS_H
#define ITEMS_H

#define ERROR_ARGC 1
#define ERROR_FILE_OPEN 2
#define ERROR_UNCORRECT_FIELD 3
#define ERROR_AMOUNT_ITEMS 4
#define ERROR_EMPTY_FILE 5
#define ERROR_NOT_ENOUGH_FIELDS 6
#define ERROR_PREFIX_LEN 7
#define ERROR_FIND_BY_PREFIX 8
#define ERROR 9

#define MAX_ARGC 3
#define MIN_ARGC 2
#define MAX_AMOUNT_ITEMS 15
#define LEN_NAME 26

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct
{
    char name[LEN_NAME + 1];
    double m;
    double v;
} item_t;

int validate_file(char *name_file);
void sort_items_by_vol_and_print(char *file_name);
int find_items_by_prefix(char *file_name, char *prefix);

#endif
