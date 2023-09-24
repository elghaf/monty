#include "monty.h"

/**
 * pint - Prints the value at the top of the stack,
 * followed by a newline.
 * @stack_beg: Double pointer to the beginning of the stack.
 * @l_num: The line number in the Monty bytecode file.
 */
void pint(stack_t **stack_beg, unsigned int l_num)
{
	if (*stack_beg == NULL || stack_beg == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", l_num);
		free(data);
		free_distant(*stack_beg);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack_beg)->n);
}
