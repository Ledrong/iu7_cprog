#include <stdio.h>
#include <string.h>

#define OK 0
#define ERROR_INPUT 1
#define ERROR_STRING_SIZE 2
#define ERROR_WORD_LEN 3
#define ERROR_AMOUNT_WORDS_IN_STRING 4
#define MAX_STRING_LEN 256
#define MAX_WORD_LEN 16
#define CORRECT_AMOUNT_WORDS_IN_STRING 1
#define AMOUNT_DIGITS_IN_OPERATOR_CODE 3
#define FUNC_WORK_SUCCESS 0
#define FUNC_WORK_FAIL 1
#define FALSE 0
#define TRUE 1
#define SEPARATORS " \n\t"
#define END_OF_ANY_STRING '\0'
#define ENTER_SYMBOL '\n'
#define NUMBERS "0123456789"
#define FIRST_CORRECT_SYMBOL_IN_NUMBER "+("


int get_word(char *string, int start_pos, int end_pos, char *result_word)
{
    int word_symbol_pos = 0;

    for (int i = start_pos; i <= end_pos && word_symbol_pos < MAX_STRING_LEN; ++i)
    {
        result_word[word_symbol_pos++] = string[i];
    }

    if (word_symbol_pos == 0)
    {
        return FUNC_WORK_FAIL;
    }

    result_word[word_symbol_pos] = END_OF_ANY_STRING;

    return FUNC_WORK_SUCCESS;
}

void add_word_in_array(char (*array)[MAX_STRING_LEN + 1], char *word, int *array_size)
{
    for (int i = 0; word[i] != END_OF_ANY_STRING; ++i)
    {
        array[*array_size][i] = word[i];
    }

    array[*array_size][strlen(word)] = END_OF_ANY_STRING;

    (*array_size)++;
}

int make_array_words(char *string, char (*array)[MAX_STRING_LEN + 1], int *array_size)
{
    int cur_word_start_pos = 0;

    for (int i = 0; string[i] != END_OF_ANY_STRING; ++i)
    {
        if (strchr(SEPARATORS, string[i]))
        {
            char cur_word[MAX_STRING_LEN + 1];

            int func_error = get_word(string, cur_word_start_pos, i - 1, cur_word);

            if (!func_error)
            {
                add_word_in_array(array, cur_word, array_size);
            }

            cur_word_start_pos = i + 1;
        }
    }

    return FUNC_WORK_SUCCESS;
}

char *skip_digits(char *number, int amount_digit_to_skip, int *success)
{
    int skipped_digits = 0;
    *success = TRUE;

    while (skipped_digits != amount_digit_to_skip && number[0] != END_OF_ANY_STRING)
    {
        if (!strchr(NUMBERS, number[0]))
        {
            *success = FALSE;
            break;
        }

        skipped_digits++;
        number++;
    }

    if (skipped_digits != amount_digit_to_skip)
    {
        *success = FALSE;
    }

    return number;
}

int good_after_code_operator(char *number)
{
    number++; //пропускаем ")"
    int success = 0;

    if (number[0] != '-')
    {
        return FALSE;
    }

    number++;

    number = skip_digits(number, 3, &success);

    if (!success)
    {
        return FALSE;
    }
    
    // пропускаем последние -DD-DD
    for (int i = 0; i < 2; ++i)
    {
        if (number[0] != '-')
        {
            return FALSE;
        }

        number++;

        number = skip_digits(number, 2, &success);

        if (!success)
        {
            return FALSE;
        }
    }

    if (number[0] != END_OF_ANY_STRING)
    {
        return FALSE;
    }

    return TRUE;
}

int good_after_code_country(char *number)
{
    if (number[0] != '(')
    {
        return FALSE;
    }

    number++;

    int success = 1;
    number = skip_digits(number, AMOUNT_DIGITS_IN_OPERATOR_CODE, &success);

    if (!success || number[0] != ')' || number[0] == END_OF_ANY_STRING)
    {
        return FALSE;
    }

    if (good_after_code_operator(number))
    {
        return TRUE;
    }

    return FALSE;
}

char *skip_code_country(char *number, int *success)
{
    int amount_skipped = 0;
    *success = TRUE;

    number++;

    while (number[0] != END_OF_ANY_STRING && number[0] != '(')
    {
        if (!strchr(NUMBERS, number[0]))
        {
            *success = FALSE;
            break;
        }

        number++;
        amount_skipped++;
    }

    if (number[0] == END_OF_ANY_STRING || amount_skipped == 0)
    {
        *success = FALSE;
    }

    return number;
}

int is_good_number(char *number)
{
    if (!strchr(FIRST_CORRECT_SYMBOL_IN_NUMBER, number[0]))
    {
        return FALSE;
    }

    if (number[0] == '+')
    {
        int success_skip = 0;
        number = skip_code_country(number, &success_skip);

        if (!success_skip)
        {
            return FALSE;
        }
    }

    if (good_after_code_country(number))
    {
        return TRUE;
    }

    return FALSE;
}

int main(void)
{
    char string[MAX_STRING_LEN + 1];

    if (!fgets(string, MAX_STRING_LEN + 1, stdin))
    {
        return ERROR_INPUT;
    }

    if (strlen(string) == 0 || string[strlen(string) - 1] != ENTER_SYMBOL)
    {
        return ERROR_STRING_SIZE;
    }

    char array_words[MAX_STRING_LEN + 1][MAX_STRING_LEN + 1];
    int array_words_size = 0;

    if (make_array_words(string, array_words, &array_words_size) == ERROR_WORD_LEN)
    {
        return ERROR_WORD_LEN;
    }

    if (array_words_size != CORRECT_AMOUNT_WORDS_IN_STRING || !is_good_number(array_words[0]))
    {
        printf("NO");
    }
    else
    {
        printf("YES");
    }

    return OK;
}
