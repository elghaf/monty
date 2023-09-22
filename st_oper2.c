#include "monty.h"

/**
 * monty_nop- Null fonction
 * @stack: Pointer to top node of the stack.
 * @line_number: Line number of of the opcode.
 */
void monty_nop(stack_t **stack, unsigned int line_number)
{
}

/**
 * swap_nodes - Swaps are two elements of the stack.
 * @stack: Pointer to top node of the stack.
 * @line_number: Line number of of the opcode.
 */
void swap_nodes(stack_t **stack, unsigned int line_number)
{
stack_t *tmp;
if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
more_error(8, line_number, "swap");
tmp = (*stack)->next;
(*stack)->next = tmp->next;
if (tmp->next != NULL)
tmp->next->prev = *stack;
tmp->next = *stack;
(*stack)->prev = tmp;
tmp->prev = NULL;
*stack = tmp;
}
/**
 * add_nodes : two function in the nodes of the stack.
 * @stack: Pointer to node of the stack.
 * @@line_number: Line number of of the opcode.
 *
 */
void add_nod(stack_t **stack, unsigned int line_number)
{
stack_t *tmp;
if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
more_error(8, line_number, "swap");
tmp = (*stack)->next;
(*stack)->next = tmp->next;
if (tmp->next != NULL)
tmp->next->prev = *stack;
tmp->next = *stack;
(*stack)->prev = tmp;
tmp->prev = NULL;
*stack = tmp;
}
/**
 * sub_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: the line number of the opcode.
 */
void sub_nod(stack_t **stack, unsigned int line_number)
{
int difference;
if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
more_error(8, line_number, "sub");
(*stack) = (*stack)->next;
difference = (*stack)->n - (*stack)->prev->n
(*stack)->n = difference;
free((*stack)->prev);
(*stack)->prev = NULL;
}
/**
 * div_nod - two finction in the nodes of the stack.
 * @stack: ointer to node of the stack.
 * @line_number: the line of the opcode.
 *
 */
void div_nod(stack_t **stack, unsigned int line_number)
{
int quotient;
if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
more_error(8, line_number, "div");
if ((*stack)->n == 0)
more_error(9, line_number);
(*stack) = (*stack)->next;
quotient = (*stack)->n / (*stack)->prev->n;
(*stack)->n = quotient;
free((*stack)->prev);
(*stack)->prev = NULL;
}
