#include "monty.h"
/**
 * free_stack - frees a stack
 * @stack : Pointer to top of stack.
 * Return: Void.
 */
void free_stack(stack_t *stack)
{
	stack_t *current = stack;

	while (current != NULL)
	{
		current = (*current).next;
		free(stack);
		stack = current;
	}
}
