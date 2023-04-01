#ifndef MYFUNCTIONS_H
#define MYFUNCTIONS_H

#define MAX_LEN_OF_WORD 11
#define MAX_STR 255

#include <stdio.h>
#include <string.h>

int input_str(char str[MAX_STR][MAX_LEN_OF_WORD]);
void reverse_str(char str[MAX_STR][MAX_LEN_OF_WORD], char newstr[MAX_STR][MAX_LEN_OF_WORD], int size);

#endif
