#include "check_mysort_key.h"

START_TEST(test_key_all_NULL)
{
    int *pb_dst = NULL, *pe_dst = NULL;
    int rc = key(NULL, NULL, &pb_dst, &pe_dst);
    ck_assert_int_eq(rc, 6);
    free(pb_dst);
}
END_TEST

Suite *test_key(void)
{
    Suite *s;
    s = suite_create("key_test");
    TCase *tc_key;
    tc_key = tcase_create("key");

    tcase_add_test(tc_key, test_key_all_NULL);
    suite_add_tcase(s, tc_key);

    return s;
}
