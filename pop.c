#include "monty.h"

/**
 * pop - Removes the top element of the stack.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: The line number in the Monty bytecode file.
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *curr;

	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	curr = *stack;
	if (curr->next == NULL)
	{
		*stack = NULL;
		free(curr);
	}
	else
	{
		*stack = curr->next;
		curr->next->prev = NULL;
		free(curr);
	}
}

