#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void find_max_element(int *matrix, int rows, int columns, int *i_max, int *j_max);
int delete_row_matrix(int **matrix, int *rows, int columns, int i_del);
int delete_column_matrix(int **matrix, int rows, int *columns, int j_del);
void copy_square_matrix(int *matrix_src, int *matrix_dst, int rows, int cols);
void make_square_matrix(int **matrix, int *rows, int *columns);
void find_min_in_row(int *matrix, int rows, int columns, int *min_i, int *min_j);
void add_row_matrix(int **matrix, int *rows, int columns, int rows_needed);
void add_columns_matrix(int **matrix, int rows, int *columns, int columns_needed);

#endif
