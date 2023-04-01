#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include "lib_dynamic_l.h"



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

typedef int (__cdecl *fn_mysort_t) (void *base, size_t num, size_t size, int (*compare)(const void *, const void *));
typedef int (__cdecl *fn_key_t) (const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);
typedef int (__cdecl *fn_correct_file_input_t) (char *f_name);
typedef int (__cdecl *fn_compare_t) (const void *i, const void *j);
typedef int (__cdecl *fn_create_array_t) (char *f_name, int **arr, int **arr_end);
typedef int (__cdecl *fn_print_array_t) (char *filename, int *begin, int *end);


int main(int argc, char **argv)
{
    if (argc < 3 || argc > 4)
        return ARGS_ERROR;

    if ((argc == 4) && (strcmp(argv[3], "f") != 0))
        return INCORRECT_FILTER;
    
    HMODULE hlib = LoadLibrary("dynamicl.dll");
    if (!hlib)
        return EXIT_FAILURE;
    
    fn_mysort_t mysort = (fn_mysort_t) GetProcAddress(hlib, "mysort");
    if (!mysort)
    {
        FreeLibrary(hlib);
        return EXIT_FAILURE;
    }
    
    fn_key_t key = (fn_key_t) GetProcAddress(hlib, "key");
    if (!key)
    {
        FreeLibrary(hlib);
        return EXIT_FAILURE;
    }
    
    fn_correct_file_input_t correct_file_input = (fn_correct_file_input_t) GetProcAddress(hlib, "correct_file_input");
    if (!correct_file_input)
    {
        FreeLibrary(hlib);
        return EXIT_FAILURE;
    }
    
    fn_compare_t compare = (fn_compare_t) GetProcAddress(hlib, "compare");
    if (!compare)
    {
        FreeLibrary(hlib);
        return EXIT_FAILURE;
    }
    
    fn_create_array_t create_array = (fn_create_array_t) GetProcAddress(hlib, "create_array");
    if (!create_array)
    {
        FreeLibrary(hlib);
        return EXIT_FAILURE;
    }
    
    fn_print_array_t print_array = (fn_print_array_t) GetProcAddress(hlib, "print_array");
    if (!print_array)
    {
        FreeLibrary(hlib);
        return EXIT_FAILURE;
    }
    

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

    FreeLibrary(hlib);
    
    return EXIT_SUCCESS;
}
