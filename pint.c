#include "monty.h"

/**
 * pint - a function that prints the value at the top of the stack.
 * @stack: the stack.
 * @line_number: for error handling.
 * Return: Nothing.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

