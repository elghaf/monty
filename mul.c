#include "monty.h"
/**
 * mul -  multiple the top with the secon
 *
 * @stacks: Double Pointer.
 * @numbers: number of line in the files.
 *
 */
void mul(stack_t **stacks, unsigned int numbers)
{
	int count;

	if (!(*stacks)->next  || !stacks || !*stacks)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line);
		free_me();
		exit(EXIT_FAILURE);
	}

	(*stacks) = (*stacks)->next;
	count = (*stacks)->n * (*stacks)->prev->n;
	(*stacks)->n = count;
	free((*stacks)->prev);
	(*stacks)->prev = NULL;
}
