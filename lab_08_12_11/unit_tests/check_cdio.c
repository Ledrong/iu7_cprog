#include "check_math_cdio.h"

START_TEST(incorrect_rows_or_columns)
{
    int m = 1, n = 1, rc = 0;
    double **matrix = allocate_matrix(n, m);
	free_matrix(matrix);
    ck_assert_int_eq(rc, 0);
}
END_TEST

Suite *test_cdio(void)
{
    Suite *s;
    s = suite_create("cdio_test");
    TCase *tc_cdio;
    tc_cdio = tcase_create("cdio");

    tcase_add_test(tc_cdio, incorrect_rows_or_columns);
    suite_add_tcase(s, tc_cdio);

    return s;
}
