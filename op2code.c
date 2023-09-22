#include "monty.h"

/**
 *_add - adds the top two elements of the stack
 *@stack: Pointer to the stack
 *@line_number: Current line number of file
 *
 * Return: Void
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, "add");
		return;
	}

	(*stack)->next->next->n -= (*stack)->next->n;
	_pop(stack, line_number);
}

/**
 *_add - adds the top two elements of the stack
 *@stack: Pointer to the stack
 *@line_number: Current line number of file
 *
 * Return: Void
 */
void _add(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, "add");
		return;
	}
}

/**
 *_nop - Doesn't do anything
 *@stack: Pointer to the stack
 *@line_number: Current line number of file
 *
 * Return: Void
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

