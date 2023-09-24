#include "monty.h"

/**
 * print_top - Prints the value at the top of the stack, followed by a newline.
 * @stk: Double pointer to the beginning of the stack.
 * @line_num: The line number in the Monty bytecode file.
 */
void print_top(stack_t **stk, unsigned int line_num)
{
    if (stk == NULL || *stk == NULL)
    {
        fprintf(stderr, "L%d: can't print, stack empty\n", line_num);
        free(tokens);
        free_dlistint(*stk);
        exit(EXIT_FAILURE);
    }
    printf("%d\n", (*stk)->n);
}

/**
 * remove_top - Removes the top element of the stack.
 * @stk: Double pointer to the beginning of the stack.
 * @line_num: The line number in the Monty bytecode file.
 */
void remove_top(stack_t **stk, unsigned int line_num)
{
    stack_t *curr;

    if (!*stk)
    {
        fprintf(stderr, "L%u: can't remove an empty stack\n", line_num);
        exit(EXIT_FAILURE);
    }
    curr = *stk;
    if (curr->next == NULL)
    {
        *stk = NULL;
        free(curr);
    }
    else
    {
        *stk = curr->next;
        curr->next->prev = NULL;
        free(curr);
    }
}

/**
 * swap_top - Swaps the top two elements of the stack.
 * @stk: Double pointer to the beginning of the stack.
 * @line_num: The line number in the Monty bytecode file.
 */

void swap_top(stack_t **stk, unsigned int line_num)
{
    int num;

    if (*stk == NULL || (*stk)->next == NULL)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
        exit(EXIT_FAILURE);
    }

    num = (*stk)->n;
    (*stk)->n = (*stk)->next->n;
    (*stk)->next->n = num;
}

/**
 * do_nothing - Does nothing.
 * @stk: Double pointer to the beginning of the stack.
 * @line_num: The line number in the Monty bytecode file.
 */
void do_nothing(stack_t **stk, unsigned int line_num)
{
    (void)stk;
    (void)line_num;
}
