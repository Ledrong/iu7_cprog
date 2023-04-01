#ifndef MY_SNPRINTF_H
#define MY_SNPRINTF_H

#include <stdlib.h>

#define MAX_STR_LENGTH 30

int my_snprintf(char *restrict buf, size_t num, const char *restrict format, ...);

#endif
