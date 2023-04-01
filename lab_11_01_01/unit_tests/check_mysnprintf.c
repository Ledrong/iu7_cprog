#include <check.h>
#include <string.h>
#include <stdio.h>
#include "my_snprintf.h"
#include "dop_functions.h"

START_TEST(test_correct_c)
{
    char buf[10], my_buf[10];
    int rc = snprintf(buf, 10, "am%czing", 'a'), my_rc = my_snprintf(my_buf, 10, "am%czing", 'a');
    int similiar = strcmp(buf, my_buf);
    ck_assert_int_eq(rc, my_rc);
    ck_assert_int_eq(similiar, 0);
}
END_TEST

START_TEST(test_correct_s)
{
    char buf[30], my_buf[30];
    int rc = snprintf(buf, 30, "I like %s", "cookies"), my_rc = my_snprintf(my_buf, 30, "I like %s", "cookies");
    int similiar = strcmp(buf, my_buf);
    ck_assert_int_eq(rc, my_rc);
    ck_assert_int_eq(similiar, 0);
}
END_TEST

START_TEST(test_correct_d)
{
    char buf[12], my_buf[12];
    int rc = snprintf(buf, 12, "5 + 5 = %d", 10), my_rc = my_snprintf(my_buf, 12, "5 + 5 = %d", 10);
    int similiar = strcmp(buf, my_buf);
    ck_assert_int_eq(rc, my_rc);
    ck_assert_int_eq(similiar, 0);
}
END_TEST

START_TEST(test_correct_i)
{
    char buf[30], my_buf[30];
    int rc = snprintf(buf, 30, "Max int number is %i", 2147483647),\
        my_rc = my_snprintf(my_buf, 30, "Max int number is %i", 2147483647);
    int similiar = strcmp(buf, my_buf);
    ck_assert_int_eq(rc, my_rc);
    ck_assert_int_eq(similiar, 0);
}
END_TEST

START_TEST(test_correct_o)
{
    char buf[12], my_buf[12];
    int rc = snprintf(buf, 12, "15 = %o", 15), my_rc = my_snprintf(my_buf, 12, "15 = %o", 15);
    int similiar = strcmp(buf, my_buf);
    ck_assert_int_eq(rc, my_rc);
    ck_assert_int_eq(similiar, 0);
}
END_TEST

START_TEST(test_correct_x)
{
    char buf[12], my_buf[12];
    int rc = snprintf(buf, 12, "15 = %x", 15), my_rc = my_snprintf(my_buf, 12, "15 = %x", 15);
    int similiar = strcmp(buf, my_buf);
    ck_assert_int_eq(rc, my_rc);
    ck_assert_int_eq(similiar, 0);
}
END_TEST

START_TEST(test_correct_hd)
{
    char buf[30], my_buf[30];
    int rc = snprintf(buf, 30, "max short = %hd", (short) 32767),\
        my_rc = my_snprintf(my_buf, 30, "max short = %hd", (short) 32767);
    int similiar = strcmp(buf, my_buf);
    ck_assert_int_eq(rc, my_rc);
    ck_assert_int_eq(similiar, 0);
}
END_TEST

START_TEST(test_correct_hi)
{
    char buf[30], my_buf[30];
    int rc = snprintf(buf, 30, "min short = %hi", (short) -32768),\
        my_rc = my_snprintf(my_buf, 30, "min short = %hi", (short) -32768);
	int similiar = strcmp(buf, my_buf);
    ck_assert_int_eq(rc, my_rc);
    ck_assert_int_eq(similiar, 0);
}
END_TEST

START_TEST(test_correct_ho)
{
    char buf[30], my_buf[30];
    int rc = snprintf(buf, 30, "15 = %ho", (short) 15),\
        my_rc = my_snprintf(my_buf, 30, "15 = %ho", (short) 15);
	int similiar = strcmp(buf, my_buf);
    ck_assert_int_eq(rc, my_rc);
    ck_assert_int_eq(similiar, 0);
}
END_TEST

START_TEST(test_correct_hx)
{
    char buf[30], my_buf[30];
    int rc = snprintf(buf, 30, "15 = %hx", (short) 15),\
        my_rc = my_snprintf(my_buf, 30, "15 = %hx", (short) 15);
	int similiar = strcmp(buf, my_buf);
    ck_assert_int_eq(rc, my_rc);
    ck_assert_int_eq(similiar, 0);
}
END_TEST

START_TEST(test_correct_ld)
{
    char buf[30], my_buf[30];
    int rc = snprintf(buf, 30, "max long = %ld", (long) 92233),\
        my_rc = my_snprintf(my_buf, 30, "max long = %ld", (long) 92233);
	int similiar = strcmp(buf, my_buf);
    ck_assert_int_eq(rc, my_rc);
    ck_assert_int_eq(similiar, 0);
}
END_TEST

START_TEST(test_correct_li)
{
    char buf[30], my_buf[30];
    int rc = snprintf(buf, 30, "max long = %li", (long) 92233),\
        my_rc = my_snprintf(my_buf, 30, "max long = %li", (long) 92233);
	int similiar = strcmp(buf, my_buf);
    ck_assert_int_eq(rc, my_rc);
    ck_assert_int_eq(similiar, 0);
}
END_TEST

START_TEST(test_correct_lo)
{
    char buf[30], my_buf[30];
    int rc = snprintf(buf, 30, "15 = %lo", (long) 15),\
        my_rc = my_snprintf(my_buf, 30, "15 = %lo", (long) 15);
	int similiar = strcmp(buf, my_buf);
    ck_assert_int_eq(rc, my_rc);
    ck_assert_int_eq(similiar, 0);
}
END_TEST

START_TEST(test_correct_lx)
{
    char buf[30], my_buf[30];
    int rc = snprintf(buf, 30, "15 = %lx", (long) 15),\
        my_rc = my_snprintf(my_buf, 30, "15 = %lx", (long) 15);
	int similiar = strcmp(buf, my_buf);
    ck_assert_int_eq(rc, my_rc);
    ck_assert_int_eq(similiar, 0);
}
END_TEST

Suite* funcs_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("tests");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_correct_c);
    tcase_add_test(tc_pos, test_correct_s);
    tcase_add_test(tc_pos, test_correct_d);
    tcase_add_test(tc_pos, test_correct_i);
    tcase_add_test(tc_pos, test_correct_o);
    tcase_add_test(tc_pos, test_correct_x);
    tcase_add_test(tc_pos, test_correct_hd);
    tcase_add_test(tc_pos, test_correct_hi);
    tcase_add_test(tc_pos, test_correct_ho);
    tcase_add_test(tc_pos, test_correct_hx);
    tcase_add_test(tc_pos, test_correct_ld);
    tcase_add_test(tc_pos, test_correct_li);
    tcase_add_test(tc_pos, test_correct_lo);
    tcase_add_test(tc_pos, test_correct_lx);
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
