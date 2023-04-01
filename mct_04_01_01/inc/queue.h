#ifndef QUEUE_H
#define QUEUE_H

#include "stack.h"

typedef struct queue queue_t;
struct queue
{
    stack_t *stack1;
    stack_t *stack2;
};

int init_queue(queue_t **queue);
int pop(queue_t *queue, int *result);
int push(queue_t *queue, int num);
int peek(queue_t *queue, int *result);
void free_queue(queue_t *queue);
int push_numbers(queue_t *queue, size_t count_of_numbers, ...);


#endif
