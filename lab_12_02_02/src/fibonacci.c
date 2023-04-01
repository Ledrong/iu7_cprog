#include "fibonacci.h"

void fibonacci(int *array, int n)
{
    for (size_t i = 0; i < n; ++i)
    {
        if (i == 0)
            array[i] = 1;
        else if (i == 1)
            array[i] = 1;
        else
            array[i] = array[i - 2] + array[i - 1];
    }
}

void delete_second_entries(int *array, int n)
{
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = n; j > 0; j--)
        {
            if (array[i] == array[j] && i == j)
            {
                for (int z = i; z < n - 1; ++z)
                    array[j] = array[z + 1];
            }
        }
    }
}

void first_entries_into_array(int *array, int *array2, int n)
{
    delete_second_entries(array, n);

    for (size_t i = 0; i < n; ++i)
        array2[i] = array[i];
}