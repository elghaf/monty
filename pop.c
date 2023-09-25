#include "monty.h"
/**
 * pop - deletes the top element.
 * @stack : Pointer to top of stack.
 * @line_number : Number of the line in .m file.
 * Return: Void.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack, *next_n;

	if (len_stack(stack) == 0)
		fprintf(stderr, "L%u: can't pop an empty stack\n",
			line_number), exit(EXIT_FAILURE);
	next_n = (*current).next;
	if (len_stack(stack) == 1)
		free(*stack);
	else
	{
		free(*stack);
		*stack = next_n;
	}
}
