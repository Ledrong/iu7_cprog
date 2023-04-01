#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node node_t;

struct node
{
    void *data;
    node_t *next;
};

int comparator(const void*, const void*);
node_t *find(node_t *head, const void *data, int (*comparator)(const void*, const void*));
void *pop_front(node_t **head);
void remove_duplicates(node_t **head, int (*comparator)(const void*, const void*));
void sorted_insert(node_t **head, node_t *element, int (*comparator)(const void*, const void*));
node_t *sort(node_t *head, int (*comparator)(const void*, const void*));

#endif

