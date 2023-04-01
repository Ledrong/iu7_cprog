#include <string.h>
#include "key.h"
#include "mysort.h"
#include "functions.h"
#include "error_codes.h"

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
