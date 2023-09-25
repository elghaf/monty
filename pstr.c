#include "monty.h"
/**
 * pstr - prints the string starting at the top of the stack,
 * followed by a new line.
 * @stack : Pointer to top of stack.
 * @line_number : Number of the line in .m file.
 * Return: Void.
 */
void pstr(stack_t **stack, unsigned int line_number
		__attribute__((unused)))
{
	stack_t *current = *stack, *stack_copy = *stack;

	if (len_stack(stack) == 0)
	{
		printf("\n");
		return;
	}
	while (current != NULL && ((*current).n > 0 && (*current).n <= 127))
	{
		printf("%c", (*current).n);
		current = (*current).next;
	}
	printf("\n");
	*stack = stack_copy;
}
