#include "monty.h"
/**
 * rotr - reverses a stack..
 * @stack : Pointer to top of stack.
 * @line_number : Number of the line in .m file..
 * Return: Void.
 */
void rotr(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *current = *stack, *previous = NULL, *next;

	if (len_stack(stack) == 0)
		return;
	while (current != NULL)
	{
		next = (*current).next;
		(*current).next = previous;
		if (previous != NULL)
			(*previous).prev = current;
		previous = current;
		current = next;
	}
	(*previous).prev = NULL;
	*stack = previous;
}
