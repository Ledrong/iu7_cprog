#include "dop_functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void write_char_to_buf(char *restrict buf, char symbol, size_t *position, size_t num, int *count)
{
    if (*position < num - 1 && buf)
        buf[(*position)++] = symbol;

    (*count)++;
}

void write_string_to_buf(char *restrict buf, char *string, size_t *position, size_t num, int *count)
{
    for (int j = 0; string[j] != '\0'; ++j)
    {
        write_char_to_buf(buf, string[j], position, num, count);
    }
}

void int_to_string(int number, char *string)
{
    int i = 0;

    if (number < 0)
    {
        ++i;
        string[0] = '-';
    }

    do
    {
        if (number >= 0)
            string[i] = '0' + number % 10;

        if (number < 0)
            string[i] = '0' - number % 10;
        number /= 10;
        ++i;
    } while (number != 0);

    string[i] = '\0';
    i--;

    for (int j = string[0] == '-' ? 1 : 0; j < i; ++j)
    {
        char tmp;
        tmp = string[j];
        string[j] = string[i];
        string[i] = tmp;
        i--;
    }
}

void long_int_to_string(long int number, char *string)
{
    int i = 0;

    if (number < 0)
    {
        ++i;
        string[0] = '-';
    }

    do
    {
        if (number >= 0)
            string[i] = '0' + number % 10;

        if (number < 0)
            string[i] = '0' - number % 10;
        number /= 10;
        ++i;
    } while (number != 0);

    string[i] = '\0';
    i--;

    for (int j = string[0] == '-' ? 1 : 0; j < i; ++j)
    {
        char tmp;
        tmp = string[j];
        string[j] = string[i];
        string[i] = tmp;
        i--;
    }
}

void short_int_to_string(short int number, char *string)
{
    int i = 0;

    if (number < 0)
    {
        ++i;
        string[0] = '-';
    }

    do
    {
        if (number >= 0)
            string[i] = '0' + number % 10;

        if (number < 0)
            string[i] = '0' - number % 10;
        number /= 10;
        ++i;
    } while (number != 0);

    string[i] = '\0';
    i--;

    for (int j = string[0] == '-' ? 1 : 0; j < i; ++j)
    {
        char tmp;
        tmp = string[j];
        string[j] = string[i];
        string[i] = tmp;
        i--;
    }
}

void tenth_to_another_base(unsigned int number, char *string, int base)
{
    int i = 0;

    do
    {
        string[i] = (char)(number % base < 10 ? '0' + number % base : 'a' + ((number % base) - 10));
        number /= base;
        ++i;
    } while (number != 0);

    string[i] = '\0';
    i--;

    for (int j = 0; j < i; ++j)
    {
        char tmp;
        tmp = string[j];
        string[j] = string[i];
        string[i] = tmp;
        i--;
    }
}

void long_tenth_to_another_base(unsigned long int number, char *string, int base)
{
    int i = 0;

    do
    {
        string[i] = (char)(number % base < 10 ? '0' + number % base : 'a' + ((number % base) - 10));
        number /= base;
        ++i;
    } while (number != 0);

    string[i] = '\0';
    i--;

    for (int j = 0; j < i; ++j)
    {
        char tmp;
        tmp = string[j];
        string[j] = string[i];
        string[i] = tmp;
        i--;
    }
}

void short_tenth_to_another_base(unsigned short int number, char *string, int base)
{
    int i = 0;

    do
    {
        string[i] = (char)(number % base < 10 ? '0' + number % base : 'a' + ((number % base) - 10));
        number /= base;
        ++i;
    } while (number != 0);

    string[i] = '\0';
    i--;

    for (int j = 0; j < i; ++j)
    {
        char tmp;
        tmp = string[j];
        string[j] = string[i];
        string[i] = tmp;
        i--;
    }
}
