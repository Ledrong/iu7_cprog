#include <string.h>
#include <stdlib.h>
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

int main(int argc, char **argv)
{
    if (argc < 3 || argc > 4)
        return ARGS_ERROR;

    if ((argc == 4) && (strcmp(argv[3], "f") != 0))
        return INCORRECT_FILTER;

    int code_return = correct_file_input(argv[1]);

    if (code_return)
        return code_return;

    int *array, *array_end;
    create_array(argv[1], &array, &array_end);

    if ((argc == 4) && (strcmp(argv[3], "f") == 0))
    {
        int *arr_begin_tmp = array, *arr_end_tmp = array_end;

        if (key(array, array_end, &arr_begin_tmp, &arr_end_tmp))
        {
            free(array);

            return NOT_KEY_ERROR;
        }

        free(array);

        array = arr_begin_tmp;
        array_end = arr_end_tmp;
    }

    mysort(array, array_end - array, sizeof(int), compare);

    print_array(argv[2], array, array_end);

    free(array);

    return EXIT_SUCCESS;
}
