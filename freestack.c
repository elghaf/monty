#include "monty.h"

/**
 * freeStack - frees a doubly linked list
 * @head: head of the stack
 */
void freeStack(stack_t *head)
{
    stack_t *stacks;

    stacks = head;
    while (head)
    {
        stacks = head->next;
        free(head);
        head = stacks;
    }
}
