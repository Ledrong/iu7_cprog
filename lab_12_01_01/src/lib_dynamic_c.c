#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib_dynamic_c.h"

#define ARGS_ERROR 1
#define INCORRECT_FILTER 2
#define NOT_KEY_ERROR 3
#define EMPTY_FILE_ERROR 4
#define COUNT_FILE_ERROR 5
#define MEMORY_ERROR 6
#define MYSORT_ERROR 7
#define SIZE_OF_ARRAY_ERROR 8
#define READ_FILE_ERROR 9
#define COUNT_ERROR 10
#define EMPTY_FILE 11

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

int compare(const void *i, const void *j)
{
	const int *a = i, *b = j;
	return *a - *b;
}

LIB_DLL int LIB_DECL mysort(void *base, size_t num, size_t size, int (*compare)(const void *, const void *))
{
	char *current_pos = (char *)base + size, *current = malloc(size), *pos;
	if (!base || num < 1)
		return SIZE_OF_ARRAY_ERROR;
	else
		for (size_t i = 1; i < num; ++i)
		{
			pos = current_pos;
			memcpy(current, current_pos, size);
			for (int j = i; j > 0 && compare(pos - size, current) > 0; --j)
			{
				memcpy(pos, pos - size, size);
				pos -= size;
			}
			memcpy(pos, current, size);
			current_pos += size;
		}
	free(current);
	return MYSORT_ERROR;
}

LIB_DLL int LIB_DECL key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    if (!pb_src || !pe_src || !pb_dst || !pe_dst || pb_src >= pe_src)
        return MEMORY_ERROR;

    int count_of_elements = count_good_in_array(pb_src, pe_src);

    if (count_of_elements == 0)
        return EMPTY_FILE_ERROR;

    *pb_dst = calloc(count_of_elements, sizeof(int));
    *pe_dst = *pb_dst + count_of_elements;

    int sum = 0, index = 0;

    for (const int *i = pb_src; i != pe_src - 1; ++i)
    {
        for (const int *j = i + 1; j != pe_src; ++j)
        {
            sum += *j;
        }

        if (*i > sum)
            *(*pb_dst + index++) = *i;

        sum = 0;
    }

    return EXIT_SUCCESS;
}
