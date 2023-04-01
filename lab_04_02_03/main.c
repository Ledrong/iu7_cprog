#include <stdio.h>
#include <string.h>

#define OK 0
#define ERROR_INPUT 1
#define ERROR_STR_OVERSIZE 2
#define ERROR_WORD_OVERSIZE 3
#define ERROR_NO_ANSWER 4
#define ERROR_EMPTY_GETTING_WORD 5
#define FUNC_WORK_SUCCESS 0

#define CODE_STRINGS_EQUAL 0

#define MAX_STR_LEN 256
#define MAX_WORD_LEN 16

#define TRUE 1
#define FALSE 0

#define SEPARATORS ",;:-.!? \n"

int write_word_to_array(char (*array)[MAX_WORD_LEN + 1], int cur_row, const char *word)
{
    int idx = 0;

    while (word[idx] != '\0')
    {
        array[cur_row][idx] = word[idx];

        idx++;
    }

    array[cur_row][idx] = '\0';

    return FUNC_WORK_SUCCESS;
}

int get_word_from_str(const char *str, int start_pos, int end_pos, char *word)
{
    if (end_pos - start_pos > MAX_WORD_LEN)
    {
        return ERROR_WORD_OVERSIZE;
    }

    int idx = 0;

    for (int i = start_pos; i < end_pos; ++i)
    {
        word[idx] = str[i];
        idx++;
    }

    if (idx == 0)
    {
        return ERROR_EMPTY_GETTING_WORD;
    }

    word[idx] = '\0';

    return FUNC_WORK_SUCCESS;
}

int make_array_words(char *str, char (*array)[MAX_WORD_LEN + 1], int *array_size)
{
    int word_start_pos = 0;

    for (int i = 0; str[i] != '\0'; ++i)
    {
        if (strchr(SEPARATORS, str[i]))
        {
            char word[MAX_WORD_LEN + 1];

            int error = get_word_from_str(str, word_start_pos, i, word);

            word_start_pos = i + 1;

            if (error == ERROR_EMPTY_GETTING_WORD)
            {
                continue;
            }
            else if (error)
            {
                return error;
            }

            write_word_to_array(array, *array_size, word);

            (*array_size)++;
        }
    }

    return FUNC_WORK_SUCCESS;
}

int is_word_in_array(char *word, char (*array)[MAX_WORD_LEN + 1], int array_size, int skipped_idx)
{
    for (int i = 0; i < array_size; ++i)
    {
        if (i == skipped_idx)
        {
            continue;
        }

        if (strcmp(word, array[i]) == CODE_STRINGS_EQUAL)
        {
            return TRUE;
        }
    }

    return FALSE;
}

int print_unique_words(char (*array_1)[MAX_WORD_LEN + 1], int size_1, char (*array_2)[MAX_WORD_LEN + 1], int size_2)
{
    int printed_something = FALSE;

    printf("Result: ");

    for (int i = 0; i < size_1; ++i)
    {
        int find_word_in_array = FALSE;

        find_word_in_array = is_word_in_array(array_1[i], array_1, size_1, i);

        if (!find_word_in_array)
        {
            find_word_in_array = is_word_in_array(array_1[i], array_2, size_2, -1);
        }

        if (!find_word_in_array)
        {
            printed_something = TRUE;
            printf("%s ", array_1[i]);
        }
    }

    for (int i = 0; i < size_2; ++i)
    {
        int find_word_in_array = FALSE;

        find_word_in_array = is_word_in_array(array_2[i], array_2, size_2, i);

        if (!find_word_in_array)
        {
            find_word_in_array = is_word_in_array(array_2[i], array_1, size_1, -1);
        }

        if (!find_word_in_array)
        {
            printed_something = TRUE;
            printf("%s ", array_2[i]);
        }
    }

    if (!printed_something)
    {
        return ERROR_NO_ANSWER;
    }

    return FUNC_WORK_SUCCESS;
}

int main(void)
{
    char str_1[MAX_STR_LEN + 2];
    char str_2[MAX_STR_LEN + 2];

    if (!fgets(str_1, MAX_STR_LEN + 2, stdin) || !fgets(str_2, MAX_STR_LEN + 2, stdin))
    {
        return ERROR_INPUT;
    }

    str_1[MAX_STR_LEN + 1] = '\0';
    str_2[MAX_STR_LEN + 1] = '\0';

    if (str_1[strlen(str_1) - 1] != '\n' || str_2[strlen(str_2) - 1] != '\n')
    {
        return ERROR_STR_OVERSIZE;
    }

    char array_words_1[MAX_STR_LEN][MAX_WORD_LEN + 1];
    int array_1_size = 0;

    int error = make_array_words(str_1, array_words_1, &array_1_size);

    if (error != FUNC_WORK_SUCCESS)
    {
        return error;
    }

    char array_words_2[MAX_STR_LEN][MAX_WORD_LEN + 1];
    int array_2_size = 0;

    error = make_array_words(str_2, array_words_2, &array_2_size);

    if (error)
    {
        return error;
    }

    error = print_unique_words(array_words_1, array_1_size, array_words_2, array_2_size);

    if (error)
    {
        return error;
    }

    return OK;
}
