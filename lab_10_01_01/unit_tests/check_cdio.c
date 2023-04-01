#include "check_math_cdio.h"

START_TEST(right_command)
{
	int rc = 0;
	ck_assert_int_eq(rc, 0);
}

Suite *test_cdio(void)
{
    Suite *s;
    s = suite_create("cdio_test");
    TCase *tc_cdio;
    tc_cdio = tcase_create("cdio");
	tcase_add_test(tc_cdio, right_command);
	
    suite_add_tcase(s, tc_cdio);

    return s;
}