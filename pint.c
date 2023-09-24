#include "monty.h"

/**
 * pint - Prints the value at the top of the stack,
 * followed by a newline.
 * @stack_beg: Double pointer to the beginning of the stack.
 * @numbers: The line number in the Monty bytecode file.
 */
void pint(stack_t **stack_beg, unsigned int numbers)
{
	if (*stack_beg)
	{
		printf("%d\n", (*stack_beg)->n);
	}
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", numbers);
		exit(EXIT_FAILURE);
	}
}