#ifndef _CHECK_MATH_FUNCTIONS_H_
#define _CHECK_MATH_FUNCTIONS_H_

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "error_codes.h"

void free_matrix(double **ptrs);
int sum_matrixes(double **matrix_a, double **matrix_b, double **result_matrix, int rows_a, int columns_a, int rows_b, int columns_b);
int multiply_matrixes(double **matrix_a, double **matrix_b, double **result_matrix, int rows_a, int columns_a, int rows_b, int columns_b);
void del_row_column(double **matrix, int rows, int columns, int row, int column, double **res_matrix);
double count_determinant(double **matrix, int rows_a, int columns_a);

#endif

