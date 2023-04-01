#include "check_mysort_key.h"

int compare_arrays(int *arr1, int len1, int *arr2, int len2)
{
    if (len1 != len2)
        return 1;

    for (int i = 0; i < len1; i++)
        if (arr1[i] != arr2[i])
            return 1;

    return 0;
}

START_TEST(test_sort_all_numbers)
{
    int arr[6] = {56, 23, 565, 22, 5678, 10};
    mysort(arr, 6, sizeof(int), &compare);
    int newarr[6] = {10, 22, 23, 56, 565, 5678};
    int rc = compare_arrays(arr, 6, newarr, 6);
    ck_assert_int_eq(rc, 0);
}
END_TEST

Suite *test_mysort(void)
{
    Suite *s;
    s = suite_create("sort_test");
    TCase *tc_key;
    tc_key = tcase_create("sort");

    tcase_add_test(tc_key, test_sort_all_numbers);
    suite_add_tcase(s, tc_key);
    return s;
}
