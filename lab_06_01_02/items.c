#include "items.h"

void set_item_name(item_t *cur_item, char *new_name)
{
    strncpy(cur_item->name, new_name, LEN_NAME);
}

char *get_item_name(item_t *cur_item)
{
    return cur_item->name;
}

void set_item_mass(item_t *cur_item, double new_mass)
{
    cur_item->m = new_mass;
}

double get_item_mass(item_t *cur_item)
{
    return cur_item->m;
}

void set_item_volume(item_t *cur_item, double new_volume)
{
    cur_item->v = new_volume;
}

double get_item_volume(item_t *cur_item)
{
    return cur_item->v;
}

void delete_end_symbol(char *str)
{
    char *pos_in_str = NULL;
    if ((pos_in_str = strchr(str, '\n')))
        *pos_in_str = '\0';
    if ((pos_in_str = strchr(str, '\r')))
        *pos_in_str = '\0';
}

int have_error_in_reading_fields(char *name, char *m, char *v, int *total_read_fields, FILE *f)
{
    if (!fgets(name, LEN_NAME + 1, f))
        return ERROR;
    (*total_read_fields)++;

    if (!fgets(m, LEN_NAME + 1, f))
        return ERROR;
    (*total_read_fields)++;

    if (!fgets(v, LEN_NAME + 1, f))
        return ERROR;
    (*total_read_fields)++;

    return EXIT_SUCCESS;
}

int correct_name(char *name)
{
    delete_end_symbol(name);

    if (strlen(name) > LEN_NAME - 1)
        return EXIT_SUCCESS;

    int only_space = 1;
    for (int i = 0; i < strlen(name) && only_space; i++)
        if (!isspace(name[i]))
            only_space = 0;
    if (only_space)
        return EXIT_SUCCESS;

    return 1;
}

int not_correct_double(char *str)
{
    for (int i = 0; i < strlen(str); ++i)
        if (!isdigit(str[i]) && str[i] != '.')
            return ERROR;
    return EXIT_SUCCESS;
}

int correct_mass(char *m)
{
    delete_end_symbol(m);

    if (not_correct_double(m))
        return EXIT_SUCCESS;

    return ERROR;
}

int correct_volume(char *v)
{
    delete_end_symbol(v);

    if (not_correct_double(v))
        return EXIT_SUCCESS;
    return ERROR;
}

int validate_file(char *name_file)
{
    FILE *f = fopen(name_file, "r");
    if (!f)
        return ERROR_FILE_OPEN;

    int red_fields = 0;
    char buf_name[LEN_NAME + 1], buf_m[LEN_NAME + 1], buf_v[LEN_NAME + 1];
    buf_name[LEN_NAME] = buf_m[LEN_NAME] = buf_v[LEN_NAME] = '\0';
    while (!have_error_in_reading_fields(buf_name, buf_m, buf_v, &red_fields, f))
    {
        if (!correct_name(buf_name) || !correct_mass(buf_m) || !correct_volume(buf_v))
            return ERROR_UNCORRECT_FIELD;
    }

    if (red_fields / 3 > MAX_AMOUNT_ITEMS)
        return ERROR_AMOUNT_ITEMS;

    if (red_fields == 0)
        return ERROR_EMPTY_FILE;

    if (red_fields % 3 != 0)
        return ERROR_NOT_ENOUGH_FIELDS;

    return EXIT_SUCCESS;
}

void get_items_from_file(char *file_name, item_t *arr, int *arr_size)
{
    FILE *f = fopen(file_name, "r");

    item_t cur_item;
    int red_fields = 0;
    char name[LEN_NAME + 1], m_buf[LEN_NAME + 1], v_buf[LEN_NAME + 1];
    name[LEN_NAME] = '\0';
    while (!have_error_in_reading_fields(name, m_buf, v_buf, &red_fields, f))
    {
        delete_end_symbol(name);
        delete_end_symbol(m_buf);
        delete_end_symbol(v_buf);

        set_item_name(&cur_item, name);
        set_item_mass(&cur_item, atof(m_buf));
        set_item_volume(&cur_item, atof(v_buf));

        arr[(*arr_size)++] = cur_item;
    }
}

int exist_prefix(char *prefix, char *str)
{
    if (strlen(prefix) > strlen(str))
        return EXIT_SUCCESS;

    int pos = 0;
    while (pos < strlen(prefix) && prefix[pos] == str[pos])
        pos++;

    if (pos != strlen(prefix))
        return EXIT_SUCCESS;
    return ERROR;
}

void sort_items_by_volume(item_t *arr, int arr_size)
{
    for (int i = 0; i < arr_size; ++i)
        for (int j = 0; j < arr_size - i - 1; ++j)
            if (get_item_mass(&arr[j]) / get_item_volume(&arr[j]) > \
                get_item_mass(&arr[j + 1]) / get_item_volume(&arr[j + 1]))
            {
                item_t t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
}

void print_items(item_t *arr, int arr_size)
{
    for (int i = 0; i < arr_size; i++)
        printf("%s\n%.6lf\n%.6lf\n", get_item_name(&arr[i]), get_item_mass(&arr[i]), \
        get_item_volume(&arr[i]));
}

void sort_items_by_vol_and_print(char *file_name)
{
    item_t arr[MAX_AMOUNT_ITEMS];
    int arr_size = 0;

    get_items_from_file(file_name, arr, &arr_size);

    sort_items_by_volume(arr, arr_size);

    print_items(arr, arr_size);
}

int print_items_with_prefix(char *prefix, item_t *arr, int arr_size)
{
    int finded_items = 0;

    for (int i = 0; i < arr_size; ++i)
        if (exist_prefix(prefix, get_item_name(&arr[i])))
        {
            print_items(&arr[i], 1);
            finded_items++;
        }

    if (finded_items == 0)
        return ERROR_FIND_BY_PREFIX;

    return EXIT_SUCCESS;
}

int find_items_by_prefix(char *file_name, char *prefix)
{
    item_t arr[MAX_AMOUNT_ITEMS];
    int arr_size = 0;

    get_items_from_file(file_name, arr, &arr_size);

    char prefix_cpy[LEN_NAME + 1];
    prefix_cpy[LEN_NAME] = '\0';
    strncpy(prefix_cpy, prefix, LEN_NAME);

    if (strcmp(prefix_cpy, "ALL") == 0)
        print_items(arr, arr_size);
    else
        return print_items_with_prefix(prefix, arr, arr_size);

    return EXIT_SUCCESS;
}
