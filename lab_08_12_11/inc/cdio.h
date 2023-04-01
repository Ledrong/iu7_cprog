#ifndef _CDIO_H_
#define _CDIO_H_

#include <stdio.h>
#include <stdlib.h>
#include "error_codes.h"

double **allocate_matrix(int rows, int columns);
void free_matrix(double **ptrs);
int input_matrix(double **matrix, FILE *f, int *rows, int *columns);
void print_matrix(double **matrix, FILE *f, int rows, int columns);

#endif
