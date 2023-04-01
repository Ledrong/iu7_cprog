#include "lib_static.h"
#include <check.h>

START_TEST(lib_static)
{
    int rc = 0;
    int arr1[] = {1, 3, 2};
    int arr2[] = {1, 2, 3};

    rc = mysort(arr1, 3, arr2, compare);

    ck_assert_int_eq(rc, 0);
}
END_TEST

Suite* funcs_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("tests");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, lib_static);
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


