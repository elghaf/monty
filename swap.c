#include "monty.h"
/**
 * swap - swaps the top two elements of the stack.
 * @stack : pointer to top of stack.
 * @line_number : Number of the line in .m file.
 * Return: Void.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack, *current, *thrd_top;

	if (len_stack(stack) < 2)
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number),
			exit(EXIT_FAILURE);
	current = (*tmp).next;
	thrd_top = (*current).next;
	*stack = (*tmp).next;
	(*current).next = tmp;
	(*current).prev = NULL;
	(*tmp).prev = current;
	(*tmp).next = thrd_top;
	(*thrd_top).prev = tmp;
}
