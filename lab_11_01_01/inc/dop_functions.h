#ifndef DOP_FUNCTIONS_H
#define DOP_FUNCTIONS_H

#include <stdlib.h>

void write_char_to_buf(char *restrict buf, char symbol, size_t *position, size_t num, int *count);
void write_string_to_buf(char *restrict buf, char *string, size_t *position, size_t num, int *count);
void int_to_string(int number, char *string);
void long_int_to_string(long int number, char *string);
void short_int_to_string(short int number, char *string);
void tenth_to_another_base(unsigned int number, char *string, int base);
void long_tenth_to_another_base(unsigned long int number, char *string, int base);
void short_tenth_to_another_base(unsigned short int number, char *string, int base);

#endif
