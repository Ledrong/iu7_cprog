#include "my_snprintf.h"
#include "dop_functions.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int my_snprintf(char *restrict buf, size_t num, const char *restrict format, ...)
{
    va_list args;
    va_start(args, format);

    if (!format)
        return EXIT_SUCCESS;
	
    size_t position = 0;
    int count = 0;

    for (int i = 0; format[i] != '\0'; ++i)
    {		
        if (format[i] == '%' && format[i + 1] == 's')
        {
            char *string = va_arg(args, char*);
			
            write_string_to_buf(buf, string, &position, num, &count);
            ++i;
        }
        else if (format[i] == '%' && (format[i + 1] == 'd' || format[i + 1] == 'i'))
        {
            int number = va_arg(args, int);
            char string[MAX_STR_LENGTH];
            string[MAX_STR_LENGTH - 1] = '\0';

            int_to_string(number, string);
            write_string_to_buf(buf, string, &position, num, &count);
            ++i;
        }
        else if (format[i] == '%' && format[i + 1] == 'c')
        {
            int symbol = va_arg(args, int);
            write_char_to_buf(buf, (char)symbol, &position, num, &count);
            ++i;
        }
        else if (format[i] == '%' && (format[i + 1] == 'o' || format[i + 1] == 'x'))
        {
            unsigned int number = va_arg(args, int);
            char string[MAX_STR_LENGTH];
            string[MAX_STR_LENGTH - 1] = '\0';

            if (format[i + 1] == 'o')
                tenth_to_another_base(number, string, 8);
            else
                tenth_to_another_base(number, string, 16);

            write_string_to_buf(buf, string, &position, num, &count);
            ++i;
        }
        else if (format[i] == '%' && format[i + 1] == 'l' && (format[i + 2] == 'd' || format[i + 2] == 'i'))
        {
            long int number = va_arg(args, long);
            char string[MAX_STR_LENGTH];
            string[MAX_STR_LENGTH - 1] = '\0';

            long_int_to_string(number, string);
            write_string_to_buf(buf, string, &position, num, &count);
            i += 2;
        }
        else if (format[i] == '%' && format[i + 1] == 'h' && (format[i + 2] == 'd' || format[i + 2] == 'i'))
        {
            int number = va_arg(args, int);
            char string[MAX_STR_LENGTH];
            string[MAX_STR_LENGTH - 1] = '\0';

            short_int_to_string((short int)number, string);
            write_string_to_buf(buf, string, &position, num, &count);
            i += 2;
        }
        else if (format[i] == '%' && format[i + 1] == 'h' && (format[i + 2] == 'o' || format[i + 2] == 'x'))
        {
            unsigned int number = va_arg(args, unsigned int);
            char string[MAX_STR_LENGTH];
            string[MAX_STR_LENGTH - 1] = '\0';

            if (format[i + 2] == 'o')
                short_tenth_to_another_base(number, string, 8);
            else
                short_tenth_to_another_base(number, string, 16);

            write_string_to_buf(buf, string, &position, num, &count);
            i += 2;
        }
        else if (format[i] == '%' && format[i + 1] == 'l' && (format[i + 2] == 'o' || format[i + 2] == 'x'))
        {
            unsigned long number = va_arg(args, long);
            char string[MAX_STR_LENGTH];
            string[MAX_STR_LENGTH - 1] = '\0';

            if (format[i + 2] == 'o')
                long_tenth_to_another_base(number, string, 8);
            else
                long_tenth_to_another_base(number, string, 16);

            write_string_to_buf(buf, string, &position, num, &count);
            i += 2;
        }
        else if (format[i] == '%')
        {
            write_char_to_buf(buf, format[i + 1], &position, num, &count);
            i++;
        }
        else
            write_char_to_buf(buf, format[i], &position, num, &count);
    }
    va_end(args);

    if (num > 0 && buf)
        buf[position] = '\0';
    else if (num == 0 && buf)
        buf[0] = '\0';
    
    return count;
}
