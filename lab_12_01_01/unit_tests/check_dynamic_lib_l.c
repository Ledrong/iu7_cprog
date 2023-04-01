#include <check.h>
#include <stdlib.h>
#include <stdio.h>
#include "windows.h"
#include "lib_dynamic_l.h"

typedef int (__cdecl *fn_mysort_t) (void *base, size_t num, size_t size, int (*compare)(const void *, const void *));
typedef int (__cdecl *fn_key_t) (const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);
typedef int (__cdecl *fn_correct_file_input_t) (char *f_name);
typedef int (__cdecl *fn_compare_t) (const void *i, const void *j);
typedef int (__cdecl *fn_create_array_t) (char *f_name, int **arr, int **arr_end);
typedef int (__cdecl *fn_print_array_t) (char *filename, int *begin, int *end);

START_TEST(dynamic_lib_l)
{
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

    int rc = 0;

    int arr1[6] = { 5, 7, 1, 9, 4, 3 };
    int arr2[6] = { 1, 3, 4, 7, 9 };

    rc = mysort(arr1, 6, sizeof(int), compare);

    for (size_t i = 0; i < 6; ++i)
    {
        if (arr1[i] != arr2[i])
            rc = 1;
    }

    ck_assert_int_eq(rc, EXIT_SUCCESS);
    FreeLibrary(hlib);
}
END_TEST

Suite* funcs_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("tests");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, dynamic_lib_l);
    suite_add_tcase(s, tc_pos);

    return s;
}

int main(void)
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = funcs_suite();

    runner = srunner_create(s);

    srunner_run_all(runner, CK_VERBOSE);

    no_failed = srunner_ntests_failed(runner);

    srunner_free(runner);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
