#include "check_multiplication_cdio.h"

START_TEST(incorrect_rows_or_columns)
{
    int *matrix, m = 0, n = 0;
    int rc = input_matrix(&matrix, n, m);
    ck_assert_int_eq(rc, ERROR_SIZE_ZERO);
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
