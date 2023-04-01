#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "queue.h"

int init_queue(queue_t **queue)
{
    *queue = malloc(sizeof(queue_t *));
    if (!*queue)
        return EXIT_SUCCESS;

    (*queue)->stack1 = NULL;
    (*queue)->stack2 = NULL;

    return EXIT_FAILURE;
}

int push(queue_t *queue, int num)
{
    return push_stack(&(queue->stack1), num);
}

int pop(queue_t *queue, int *result)
{
    if (!queue || !result || !queue->stack1)
        return EXIT_FAILURE;

    int tmp = 0;
    while(pop_stack(&(queue->stack1), &tmp) == 0)
        push_stack(&(queue->stack2), tmp);

    pop_stack(&(queue->stack2), &tmp);
    *result = tmp;

    while(pop_stack(&(queue->stack2), &tmp) == 0)
        push_stack(&(queue->stack1), tmp);

    return EXIT_SUCCESS;
}

int peek(queue_t *queue, int *result)
{
    if (!queue || !result || !queue->stack1)
        return EXIT_FAILURE;

    int tmp = 0;
    while(pop_stack(&(queue->stack1), &tmp) == 0)
        push_stack(&(queue->stack2), tmp);

    *result = tmp;

    while(pop_stack(&(queue->stack2), &tmp) == 0)
        push_stack(&(queue->stack1), tmp);

    return EXIT_SUCCESS;
}

void free_queue(queue_t *queue)
{
    free_stack(&(queue->stack1));
    free_stack(&(queue->stack2));
    free(queue);
}

int push_numbers(queue_t *queue, size_t count_of_numbers, ...)
{
    va_list args;
    va_start(args, count_of_numbers);
    for (size_t i = 0; i < count_of_numbers; ++i)
    {
        int cur_num = va_arg(args, int);
        int rc = push(queue, cur_num);
        if (rc)
            return rc;
    }

    return EXIT_SUCCESS;
}
