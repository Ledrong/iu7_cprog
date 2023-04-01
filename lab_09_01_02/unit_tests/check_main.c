#include "items.h"
#include "check.h"
#include <stdio.h>

START_TEST(incorrect_volume)
{
	char v[] = "p";
    int rc = 0;
	rc = correct_volume(v);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

Suite* funcs_suite(void)
{
    Suite *s;
    TCase *tc_neg;

    s = suite_create("funcs");

    tc_neg = tcase_create("positives");
    tcase_add_test(tc_neg, incorrect_volume);
    suite_add_tcase(s, tc_neg);

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
