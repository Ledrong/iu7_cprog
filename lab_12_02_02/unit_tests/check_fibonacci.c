#include <check.h>
#include "fibonacci.h"

START_TEST(test_fibonacci)
{
    int arr1[5] = {1, 1, 2, 3, 5};
    int arr2[5];
    int rc = 0;
    fibonacci(arr2, 5);
    for (size_t i = 0; i < n; ++i)
        if (arr1[i] != arr2[i])
            rc = 1
    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(test_first_entries)
{
    int arr1[5] = {1, 1, 2, 3, 5};
    int arr2[5];
    int rc = 0;
    first_entries_into_array(arr2, 5);
    if (arr2[0] != 1 || arr2[1] != 2 || arr2[2] != 3 || arr2[3] != 5)
        rc = 1;
    ck_assert_int_eq(rc, 0);
}
END_TEST

Suite* funcs_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("tests");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_fibonacci);
    tcase_add_test(tc_pos, test_first_entries);
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
