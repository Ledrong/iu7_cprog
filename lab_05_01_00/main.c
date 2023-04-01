#include <stdio.h>

#define OK 0
#define SCANF_CHECK 1

#define SOLUTION_EXIST_ERROR -1

int process(FILE *f, int *solution)
{
    int current_member = 0, max_pos = -1, flag = 3;
    int rc = fscanf(f, "%d", &current_member);
    while (rc == 1)
    {
        if ((current_member > 0) && (current_member > max_pos) && flag < 3)
        {
            max_pos = current_member;
        }

        if (current_member > 0)
        {
            flag = 3;
        }

        if (current_member < 0)
        {
            flag = 2;
        }

        rc = fscanf(f, "%d", &current_member);
    }

    if (max_pos == -1)
    {
        return SOLUTION_EXIST_ERROR;
    }

    *solution = max_pos;

    return OK;
}

int main(void)
{
    int solution, work = process(stdin, &solution);

    if (work == SOLUTION_EXIST_ERROR)
    {
        return SOLUTION_EXIST_ERROR;
    }

    printf("%d", solution);

    return OK;
}