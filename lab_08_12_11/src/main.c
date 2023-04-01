#include "math_functions.h"
#include "cdio.h"
#include "error_codes.h"

int main(int argc, char **argv)
{
	if (argc < 4 || argc > 5)
		return ERROR_ARGC;

	if ((strcmp(argv[1], "a") != 0) && (strcmp(argv[1], "m") != 0) && (strcmp(argv[1], "o") != 0))
		return OPERATION_ERROR;

	int rows_a = 0, columns_a = 0;

	FILE *f1 = fopen(argv[2], "r");

	if (f1 == NULL)
		return FILE_OPEN_ERROR;

	if (fscanf(f1, "%d%d", &rows_a, &columns_a) != 2)
		return ERROR_MATRIX_SIZE;

	if (rows_a <= 0 || columns_a <= 0)
		return ERROR_MATRIX_SIZE;

	double **matrix_a;
	matrix_a = allocate_matrix(rows_a, columns_a);

	if (input_matrix(matrix_a, f1, &rows_a, &columns_a))
		return DATA_MATRIX_ERROR;

	fclose(f1);

	int rows_b = 0, columns_b = 0;

	double **matrix_b;
	if (argc > 4)
	{
		FILE *f2 = fopen(argv[3], "r");

		if (f2 == NULL)
		{
			free_matrix(matrix_a);
			return FILE_OPEN_ERROR;
		}

		if (fscanf(f2, "%d%d", &rows_b, &columns_b) != 2)
		{
			free_matrix(matrix_a);
			return ERROR_MATRIX_SIZE;
		}

		if (rows_b <= 0 || columns_b <= 0)
		{
			free_matrix(matrix_a);
			return ERROR_MATRIX_SIZE;
		}

		matrix_b = allocate_matrix(rows_b, columns_b);

		if (input_matrix(matrix_b, f2, &rows_b, &columns_b))
		{
			free_matrix(matrix_a);

			return DATA_MATRIX_ERROR;
		}

		fclose(f2);
	}
	char *filename;
	if (argc == 5)
		filename = argv[4];
	else if (argc == 4)
		filename = argv[3];

	switch (argv[1][0])
	{
		case 'a':
			{
				double **res_matrix;
				res_matrix = allocate_matrix(rows_a, columns_b);
				if (sum_matrixes(matrix_a, matrix_b, res_matrix, rows_a, columns_a, rows_b, columns_b))
				{
					free_matrix(matrix_a);
					free_matrix(matrix_b);
					free_matrix(res_matrix);
					return DIFFERENT_SIZE_ERROR;
				}
				FILE *f = fopen(filename, "w");
				if (f == NULL)
				{
					free_matrix(matrix_a);
					free_matrix(matrix_b);
					free_matrix(res_matrix);
					return FILE_OPEN_ERROR;
				}
				print_matrix(res_matrix, f, rows_a, columns_b);
				fclose(f);
				free_matrix(matrix_a);
				free_matrix(matrix_b);
				free_matrix(res_matrix);
				break;
			}
		case 'm':
			{
				double **res_matrix;
				res_matrix = allocate_matrix(rows_a, columns_b);
				if (multiply_matrixes(matrix_a, matrix_b, res_matrix, rows_a, columns_a, rows_b, columns_b))
				{
					free_matrix(matrix_a);
					free_matrix(matrix_b);
					free_matrix(res_matrix);
					return DIFFERENT_SIZE_ERROR;
				}
				FILE *f = fopen(filename, "w");
				if (f == NULL)
				{
					free_matrix(matrix_a);
					free_matrix(matrix_b);
					free_matrix(res_matrix);
					return FILE_OPEN_ERROR;
				}
				print_matrix(res_matrix, f, rows_a, columns_b);
				fclose(f);
				free_matrix(matrix_a);
				free_matrix(matrix_b);
				free_matrix(res_matrix);
				break;
			}
		case 'o':
			{
				if (rows_a != columns_a)
				{
					free_matrix(matrix_a);
					return DIFFERENT_SIZE_ERROR;
				}

				double d = 0.0;
				FILE *f = fopen(filename, "w");
				if (f == NULL)
				{
					free_matrix(matrix_a);
					return FILE_OPEN_ERROR;
				}
				d = count_determinant(matrix_a, rows_a, columns_a);
				fprintf(f, "%lf", d);
				fclose(f);
				free_matrix(matrix_a);
				break;
			}
	}

	return EXIT_SUCCESS;
}
