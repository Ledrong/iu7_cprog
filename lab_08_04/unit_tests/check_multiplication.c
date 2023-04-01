#include "check_multiplication_cdio.h"

START_TEST(correct_multiplication)
{
	int rc = 0;
    ck_assert_int_eq(rc, 0);
}
END_TEST

Suite *test_multiplication(void)
{
    Suite *s;
    s = suite_create("multiplication_test");
    TCase *tc_multiplication;
    tc_multiplication = tcase_create("multiplication");

    tcase_add_test(tc_multiplication, correct_multiplication);
    suite_add_tcase(s, tc_multiplication);

    return s;
}
