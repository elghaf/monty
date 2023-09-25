#include "monty.h"
/**
 * free_stack - Frees a stack_t stack.
 * @stack: Pointer to the top of the stack.
 *
 * Return: void
 */
void free_stack(stack_t *stack)
{
	stack_t *swap;

	while (stack != NULL)
	{
		swap = stack;
		stack = stack->next;
		free(swap);
	}
}
