#include "list.h"

int comparator(const void *p, const void *q)
{
    const int *l = p;
    const int *m = q;

    return (*l - *m);
}

node_t *find(node_t *head, const void *data, int (*comparator)(const void*, const void*))
{
    if (!head)
        return NULL;

    if (!data)
        return NULL;

    node_t *cur_element = head;

    while (cur_element != NULL)
    {
        if (comparator(data, cur_element->data) == 0)
        {
            return cur_element;
        }

        cur_element = cur_element->next;
    }

    return NULL;
}

void *pop_front(node_t **head)
{
    if (!head || !*head)
        return NULL;

    node_t *cur_element = *head;
    void  *data = cur_element->data;

    *head = (*head)->next;
    free(cur_element);

    return data;
}

void remove_duplicates(node_t **head, int (*comparator)(const void*, const void*))
{
    if (!head || !*head)
        return;

    node_t *cur_element = *head;

    while (cur_element->next != NULL)
    {
        if (comparator(cur_element->data, cur_element->next->data) == 0)
        {
            node_t *cur_next = cur_element->next;
            cur_element->next = cur_next->next;

            free(cur_next);
        }
        else
            cur_element = cur_element->next;
    }

    return;
}

void sorted_insert(node_t **head, node_t *element, int (*comparator)(const void*, const void*))
{
    if (!*head)
    {
        *head = element;
        element->next = NULL;

        return;
    }

    node_t *cur_element = *head;

    if (comparator(cur_element->data, element->data) > 0)
    {
        element->next = *head;
        *head = element;
        return;
    }

    node_t *prev_element = NULL;

    element->next = NULL;

    while (cur_element != NULL)
    {
        if (comparator(cur_element->data, element->data) > 0)
        {
            element->next = cur_element;
            prev_element->next = element;

            return;
        }

        prev_element = cur_element;
        cur_element = cur_element->next;
    }

    if (element->next == NULL)
    {
        prev_element->next = element;
    }
}

node_t *sort(node_t *head, int (*comparator)(const void*, const void*))
{
    if (!head)
        return NULL;

    node_t *cur_element = head;

    if (cur_element->next == NULL)
        return head;

    node_t *prev_cur_element = head;
    cur_element = cur_element->next;
    node_t *next_cur_element = cur_element->next;

    prev_cur_element->next = NULL;

    while (cur_element != NULL)
    {
        next_cur_element = cur_element->next;

        sorted_insert(&head, cur_element, comparator);
        cur_element = next_cur_element;
    }

    return head;
}



