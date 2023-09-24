#include "monty.h"

/**
 * pint - Prints the value at the top of the stack,
 * followed by a newline.
 * @stack_beg: Double pointer to the beginning of the stack.
 * @l_num: The line number in the Monty bytecode file.
 */
void pint(stack_t **stack_beg, unsigned int l_num)
{
	if (*stack_beg)
	{
		printf("%d\n", (*stack_beg)->n);
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", l_num);
		exit(EXIT_FAILURE);
	}
}