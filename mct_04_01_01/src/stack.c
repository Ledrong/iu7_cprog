#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

stack_t *create_stack_elem(int data)
{
    stack_t *new_stack_elem = malloc(sizeof(stack_t));
    if (!new_stack_elem)
        return NULL;

    new_stack_elem->data = data;
    new_stack_elem->prev = NULL;

    return new_stack_elem;
}

int push_stack(stack_t **stack, int data)
{
    stack_t *stack_new = *stack;
    if (!stack_new)
    {
        *stack = create_stack_elem(data);
        if (!(*stack))
            return EXIT_FAILURE;
        return EXIT_SUCCESS;
    }

    stack_t *new_elem = create_stack_elem(data);
    if (!new_elem)
        return EXIT_FAILURE;

    new_elem->prev = *stack;
    *stack = new_elem;

    return EXIT_SUCCESS;
}

int pop_stack(stack_t **stack, int *res)
{
    if (!(*stack))
        return EXIT_FAILURE;

    *res = (*stack)->data;

    stack_t *deleting_elem = *stack;
    *stack = (*stack)->prev;
    free(deleting_elem);

    return EXIT_SUCCESS;
}

void print_stack(stack_t *stack)
{
    if (!stack)
	{
		printf("empty stack\n");
		return;
	}

    stack_t *cur = stack;
    while (cur)
    {
        printf("%d ", cur->data);
        cur = cur->prev;
    }
    printf("\n");
}

void free_stack(stack_t **stack)
{
    int tmp = 0;
    while(pop_stack(stack, &tmp) == EXIT_SUCCESS);
}
