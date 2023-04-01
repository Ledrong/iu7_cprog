#ifndef __CHECK_MYSORT_KEY_H__
#define __CHECK_MYSORT_KEY_H__

#include <check.h>
#include <stdlib.h>
#include "../inc/mysort.h"
#include "../inc/functions.h"
#include "../inc/key.h"

int compare_arrays(int *arr1, int len1, int *arr2, int len2);
Suite *test_mysort(void);
Suite *test_key(void);

#endif
