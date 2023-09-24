#include "monty.h"

/**
 * pop - Removes the top element of the stack.
 * @stack_beg: Double pointer to the beginning of the stack.
 * @l_num: The line number in the Monty bytecode file.
 */

void pop(stack_t **stack_beg, unsigned int l_num)
{
	stack_t *cc;

	if (!*stack_beg)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", stack_beg);
		exit(EXIT_FAILURE);
	}
	cc = *stack_beg;
	if(cc->next == NULL)
	{
		*stack_beg = NULL;
		free(cc);
	}
	else
	{
		*stack_beg = cc->next;
		cc->next->prev = NULL;
		free(cc);
	}
}

