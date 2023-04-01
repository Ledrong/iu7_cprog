#include <stdlib.h>
#include "key.h"
#include "functions.h"
#include "error_codes.h"

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    if (!pb_src || !pe_src || !pb_dst || !pe_dst || pb_src >= pe_src)
        return MEMORY_ERROR;

    int count_of_elements = count_good_in_array(pb_src, pe_src);

    if (count_of_elements == 0)
        return EMPTY_FILE_ERROR;

    *pb_dst = calloc(count_of_elements, sizeof(int));
    *pe_dst = *pb_dst + count_of_elements;

    int sum = 0, index = 0;

    for (const int *i = pb_src; i != pe_src - 1; ++i)
    {
        for (const int *j = i + 1; j != pe_src; ++j)
        {
            sum += *j;
        }

        if (*i > sum)
            *(*pb_dst + index++) = *i;

        sum = 0;
    }

    return EXIT_SUCCESS;
}
