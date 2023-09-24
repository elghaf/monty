#include "monty.h"

/**
 * pint - Prints the value at the top of the stack,
 * followed by a newline.
 * @stacks: Double pointer to the beginning of the stack.
 * @numbers: The line number in the Monty bytecode file.
 */
void pint(stack_t **stacks, unsigned int numbers)
{
	if (*stacks)
	{
		printf("%d\n", (*stacks)->n);
	}
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", numbers);
		exit(EXIT_FAILURE);
	}
}