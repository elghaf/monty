#include "monty.h"
/**
 * rotl - rotates the stack to the top.
 * @stack : Pointer to top of stack.
 * @line_number : Number of the line in .m file.
 * Return: Void.
 */
void rotl(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *current = *stack, *copy_stack = *stack;

	if (len_stack(stack) == 0)
		return;
	*stack = (*current).next;
	while ((*current).next != NULL)
		current = (*current).next;
	(*current).next = copy_stack;
	(*copy_stack).next = NULL;
	(*copy_stack).prev = current;
}
