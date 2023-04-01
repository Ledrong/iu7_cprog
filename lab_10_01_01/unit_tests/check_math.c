#include "check_math_cdio.h"

START_TEST(right_pop_front)
{
    int rc = 0;
    ck_assert_int_eq(rc, 0);
}
END_TEST

Suite *test_math(void)
{
    Suite *s;
    s = suite_create("math");
    TCase *tc_math;
    tc_math = tcase_create("math");

    tcase_add_test(tc_math, right_pop_front);
    suite_add_tcase(s, tc_math);

    return s;
}
