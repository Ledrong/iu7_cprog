double second_max(double **matrix, int n, int m)
{
    double max1 = matrix[0][0], max2 = matrix[0][0];

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            if  (matrix[i][j] > max1)
            {
                max2 = max1;
                max1 = matrix[i][j];
            }
    }
    return max2;
}

void sort_matrix(double ***array, int n, int rows, int columns)
{
    for (int i = 0; i < n - 1; ++i)
    {
        if (second_max(array[i - 1], rows, columns) > second_max(array[i], rows, columns))
        {
            double **temp = array[i - 1];
            array[i - 1] = array[i];
            array[i] = temp;
        }
    }
}