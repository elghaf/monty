#include "monty.h"
/**
 * mul - multiplies the second top element of the stack with the top element
 * of the stack.
 * @stack : Pointer to top of stack.
 * @line_number : Number of the line in .m file.
 * Return: Void.
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *next_n, *current = *stack;

	if (len_stack(stack) < 2)
		fprintf(stderr, "L%u: can't mul, stack too short\n",
			line_number), exit(EXIT_FAILURE);
	next_n = (*current).next;
	(*next_n).n *= (*current).n;
	free(*stack);
	*stack = next_n;
}
