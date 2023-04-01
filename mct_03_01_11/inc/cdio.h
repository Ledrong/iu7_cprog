#ifndef _CDIO_H_
#define _CDIO_H_

#include <stdio.h>
#include <stdlib.h>

double **allocate_matrix(int rows, int columns);
void free_matrix(double **ptrs);
int input_matrix(double **matrix, int *rows, int *columns);
void print_matrix(double ***array, int n);

#endif