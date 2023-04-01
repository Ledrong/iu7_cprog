#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__
#include <stdio.h>

int count_of_numbers(FILE *file, int *count);
int correct_file_input(char *f_name);
int fill_array(FILE *f, int *arr, int *arr_end);
int create_array(char *f_name, int **arr, int **arr_end);
int count_good_in_array(const int *arr, const int *arr_end);
void print_array(char *filename, int *begin, int *end);

#endif
