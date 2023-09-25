#include "monty.h"
/**
 * len_stack - returns the number of elements in the stack.
 * @stack : Pointer to top of stack..
 * Return: Number of elements in stack.
 */
size_t len_stack(stack_t **stack)
{
	size_t len = 0;

	while (*stack != NULL)
	{
		len++;
		*stack = (**stack).next;
	}
	return (len);
}
