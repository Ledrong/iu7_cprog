#include <stdio.h>

#include "fibonacci.h"

int main()
{
    int arr1[5] = {0};
    int arr2[5];
    char *res;

    printf("Fill by fibonacci: \n");
    test_fibonacci("Test correct:", arr1, 5, res);
    printf("%s", res);

    int arr3[5] = {1, 1, 3, 3);
    int arr4[5];
    char *res2;
    printf("\nTest first_entries: \n");
    test_first_entries("Test correct:", arr3, arr4, 5, res2);
    printf("%s", res2);
    return 0;
}

void test_fibonacci(int *array, int n, char *res)
{
    fibonacci(array, 5);

    int rc = 0;
    if (arr2[0] != 1 || arr2[1] != 1 || arr2[2] != 2 || arr2[3] != 3 || arr2[4] != 5)
        rc = 1;

    if (rc == 1)
        res = "Failed";
    else
        res = "Passed";
}

void first_entries_into_array(int *array, int *array2, int n, char *res)
{
    first_entries_into_array(array, array2, n);
    int rc = 0;

    if (array2[0] != 1 || array2[1] != 3)
        rc = 1;

    if (rc == 1)
        res = "Failed";
    else
        res = "Passed";
}
