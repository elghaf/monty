#include "monty.h"

/**
 * pop - Removes the top element of the stack.
 * @stacks: Double pointer to the beginning of the stack.
 * @numbers: The line number in the Monty bytecode file.
 */

void pop(stack_t **stacks, unsigned int numbers)
{
	stack_t *cc;

	if (!*stacks)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", numbers);
		exit(EXIT_FAILURE);
	}
	cc = *stacks;
	if(cc->next == NULL)
	{
		*stacks = NULL;
		free(cc);
	}
	else
	{
		*stacks = cc->next;
		cc->next->prev = NULL;
		free(cc);
	}
}

