#include <check.h>
#include <stdlib.h>
#include <stdio.h>
#include "lib_dynamic_c.h"

START_TEST(dynamic_lib_c)
{
    int rc = 0;

    int arr1[3] = { 5, 7, 1 };
    int arr2[3] = { 1, 5, 7 };

    rc = mysort(arr1, 3, sizeof(int), compare);

    for (size_t i = 0; i < 3; ++i)
    {
        if (arr1[i] != arr2[i])
            rc = 1;
    }

    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

Suite* funcs_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("tests");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, dynamic_lib_c);
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
