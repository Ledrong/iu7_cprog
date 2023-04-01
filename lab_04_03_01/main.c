#include <stdio.h>
#include <string.h>
#include <stddef.h>

#define OK 0
#define ERROR 1

int first_check(const char *word, const int position)
{
    for (int i = 0; i < position; i++)
    {
        if (word[i] == word[position])
        {
            return OK;
        }
    }

    return ERROR;
}

void make_str(char *new_str, const char *word)
{
    int i = 0, k = strlen(new_str);

    while (word[i] != '\0')
    {
        if (first_check(word, i))
        {
            new_str[k++] = word[i];
        }

        i++;
    }

    new_str[k] = ' ';
}

void print_result(char *new_str)
{
    new_str[strlen(new_str) - 1] = '\0';

    printf("Result: %s\n", new_str);
}

int str_w(char *str, char **array)
{
    char sep[15] = " ,;:-.!?\n\t\r\f\v";
    char *str_r;

    str_r = strtok(str, sep);

    int i = 0;

    while (str_r != NULL)
    {
        if (strlen(str_r) > 18 - 2)
        {
            return ERROR;
        }

        array[i] = str_r;
        i++;
        str_r = strtok(NULL, sep);
    }

    return i;
}

int main(void)
{
    char str[257];
    
    if (fgets(str, 257, stdin) == NULL || (strlen(str) >= 257 - 1) || strlen(str) < 2)
    {
        return ERROR;
    }

    char *array[18];
    char new_str[257] = { '\0' };

    int size = str_w(str, array);

    if (size < 2)
    {
        return ERROR;
    }

    for (int i = size - 2; i >= 0; i--)
    {
        if (strcmp(array[i], array[size - 1]) != 0)
        {
            make_str(new_str, array[i]);
        }
    }

    if (strlen(new_str) == 0)
    {
        return ERROR;
    }

    print_result(new_str);

    return OK;
}
