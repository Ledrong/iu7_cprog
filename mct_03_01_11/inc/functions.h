#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

#include <stdlib.h>
#include <stdio.h>
#define N_ERROR 1
#define SIZE_ERROR 2
#define MATRIX_ELEMENT_ERROR 3

double second_max(double **matrix, int n, int m);
void sort_matrix(double ***array, int n, int rows, int columns);

#endif