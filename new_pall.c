#include "monty.h"

void new_pall(stack_t **head, unsigned int new_var)
{
    stack_t *current = *head;

    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}
