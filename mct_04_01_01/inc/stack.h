#ifndef STACK_H
#define STACK_H

typedef struct stack stack_t;
struct stack
{
    int data;
    stack_t *prev;
};

int push_stack(stack_t **stack, int data);
int pop_stack(stack_t **stack, int *res);
void print_stack(stack_t *stack);
void free_stack(stack_t **stack);

#endif
