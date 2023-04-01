#include <stdio.h>
#include <stdlib.h>
#include "error_codes.h"

int count_of_numbers(FILE *file, int *count)
{
    int number;
    while (fscanf(file, "%d", &number) == 1)
    {
        (*count)++;
    }

    if (!feof(file))
        return COUNT_FILE_ERROR;

    return EXIT_SUCCESS;
}

int correct_file_input(char *f_name)
{
    FILE *f = fopen(f_name, "r");

    if (!f)
        return READ_FILE_ERROR;

    int count_of_elements = 0;

    if (count_of_numbers(f, &count_of_elements))
        return COUNT_ERROR;

    fclose(f);

    if (count_of_elements == 0)
        return EMPTY_FILE;

    return EXIT_SUCCESS;
}

void fill_array(FILE *f, int *arr, int *arr_end)
{
    while (arr != arr_end)
    {
        fscanf(f, "%d", arr);
        arr++;
    }
}

int create_array(char *f_name, int **arr, int **arr_end)
{
    FILE *f = fopen(f_name, "r");

    int count_of_elements = 0;
    count_of_numbers(f, &count_of_elements);

    *arr = calloc(count_of_elements, sizeof (int));

    *arr_end = *arr + count_of_elements;

    rewind(f);
    fill_array(f, *arr, *arr_end);

    fclose(f);

    return EXIT_SUCCESS;
}

int count_good_in_array(const int *arr, const int *arr_end)
{
    int sum = 0, count = 0;
    for (const int *i = arr; i != arr_end - 1; ++i)
    {
        for (const int *j = i + 1; j != arr_end; ++j)
        {
            sum += *j;
        }
        if (*i > sum)
            count++;

        sum = 0;
    }

    return count;
}

void print_array(char *filename, int *begin, int *end)
{
    FILE *f = fopen(filename, "w");

    for (int *i = begin; i < end; ++i)
        fprintf(f, "%d ", *i);

    fclose(f);
}
