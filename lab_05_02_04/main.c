#include <stdio.h>
#include <stdlib.h>

#define OK 0
#define SCANF_CHECK 1

#define SOLUTION_EXIST_ERROR -1

int find_min_element_pos(FILE *f)
{
    int min_element, pos_min = 0;

    fscanf(f, "%d", &min_element);

    int current_number = 0, idx = 1;

    while (fscanf(f, "%d", &current_number) == 1)
    {
        if (current_number < min_element)
        {
            min_element = current_number;

            pos_min = idx;
        }

        idx++;
    }

    return pos_min;
}

int find_max_element_pos(FILE *f)
{
    int max_element, pos_max = 0;

    fscanf(f, "%d", &max_element);

    int current_number = 0, idx = 1;

    while (fscanf(f, "%d", &current_number) == 1)
    {
        if (current_number > max_element)
        {
            max_element = current_number;

            pos_max = idx;
        }

        idx++;
    }

    return pos_max;
}

float find_average_value(FILE *f, int max_pos, int min_pos)
{
    int beginning_pos = max_pos, finishing_pos = min_pos;

    if (max_pos > min_pos)
    {
        beginning_pos = min_pos;

        finishing_pos = max_pos;
    }

    int pos = 0, count_of_numbers = 0, sum = 0, current_number = 0;

    while ((fscanf(f, "%d", &current_number) == 1) && pos < finishing_pos)
    {
        if (pos > beginning_pos)
        {
            sum += current_number;

            count_of_numbers++;
        }

        pos++;
    }

    float average_value = (float)sum / (float)count_of_numbers;

    return average_value;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        return 1;
    }

    FILE *f = fopen(argv[1], "r");

    if (!f)
    {
        return 1;
    }

    int max_pos = find_max_element_pos(f);

    rewind(f);

    int min_pos = find_min_element_pos(f);

    rewind(f);

    if (abs(max_pos - min_pos) <= 1)
    {
        fclose(f);

        return 1;
    }

    float answer = find_average_value(f, max_pos, min_pos);

    fclose(f);

    printf("%f", answer);

    return 0;
}
