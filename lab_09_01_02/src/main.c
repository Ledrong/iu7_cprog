#include "items.h"

int main(int argc, char **argv)
{
    if (argc < MIN_ARGC || argc > MAX_ARGC)
        return ERROR_ARGC;

    if (argc == MAX_ARGC && strlen(argv[2]) > LEN_NAME)
        return ERROR_PREFIX_LEN;

    int error = validate_file(argv[1]);
    if (error)
        return error;

    if (argc == MIN_ARGC)
        sort_items_by_vol_and_print(argv[1]);
    else
        return find_items_by_prefix(argv[1], argv[2]);

    return EXIT_SUCCESS;
}
