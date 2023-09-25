#include "monty.h"
/**
 * pall - prints all the elements of a stack
 * @stack : Pointer to top of stack.
 * @line_number : Number of the line in .m file.
 * Return: Void.
 */
void pall(stack_t **stack, unsigned int line_number
		__attribute__((unused)))
{
	stack_t *current = *stack, *stack_copy = *stack;

	if (len_stack(stack) == 0)
		return;
	while (current != NULL)
	{
		printf("%d\n", (*current).n);
		current = (*current).next;
	}
	*stack = stack_copy;
}
