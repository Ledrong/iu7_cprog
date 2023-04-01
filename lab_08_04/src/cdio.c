#include "cdio.h"

int input_matrix(int **matrix, int rows, int columns)
{
	if (rows <= 0 || columns <= 0)
		return ERROR_SIZE_ZERO;

	*matrix = malloc(rows * columns * sizeof(int));

	if (!(*matrix))
	{
		printf("Не удалось выделить память под матрицу\n");

		return DATA_MATRIX_ERROR;
	}

	int element = 0;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (scanf("%d", &element) != 1)
			{
				printf("В качестве элемента матрицы можно вводить только целое число\n");
				free(*matrix);
				return ELEMENT_ERROR;
			}
			(*matrix)[i * columns + j] = element;
		}
	}

	return EXIT_SUCCESS;
}

void print_matrix(int *matrix, int rows, int columns)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
			printf("%d ", matrix[i * columns + j]);
		printf("\n");
	}
}
