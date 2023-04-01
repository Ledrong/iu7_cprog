#include <stdio.h>
#include <string.h>

#define MAX_LEN_STR 15
#define COUNT_TESTS 4
#define TEST_OK 1
#define TEST_FAIL 0
#define OK 0

char *my_strrchr(char *const str, const int symbol)
{
    int i = 0;
    char *pointer = NULL;

    while (str[i])
    {
        if (str[i] == (char)symbol)
        {
            pointer = &str[i];
        }
        i++;
    }

    if (symbol == '\0')
    {
        pointer = &str[i];
    }

    return pointer;
}

const int strrchr_tests(char *const array, const int code)
{
    if (my_strrchr(array, code) == strrchr(array, code))
    {
        return TEST_OK;
    }

    return TEST_FAIL;
}

void print_result_of_test(const int num, const int res)
{
    printf("Test %d: %d\n", num, res);
}

int main(void)
{
    char tests_arr[COUNT_TESTS][MAX_LEN_STR] = { "hello", "test", "cat", "" };
    char symbols_code[COUNT_TESTS] = { 69, 0, 56, 76 };

    for (int i = 0; i < COUNT_TESTS; i++)
    {
        print_result_of_test(i + 1, strrchr_tests(tests_arr[i], symbols_code[i]));
    }

    return OK;
}
