#include "monty.h"
/**
 * division - divides the second top element of the stack by the top element of
 * the stack.
 * @stack : Pointer to top of stack.
 * @line_number : Number of the line in .m file.
 * Return: Void.
 */
void division(stack_t **stack, unsigned int line_number)
{
	stack_t *next_n, *current = *stack;

	if (len_stack(stack) < 2)
		fprintf(stderr, "L%u: can't div, stack too short\n",
			line_number), exit(EXIT_FAILURE);
	next_n = (*current).next;
	if ((*current).n == 0)
		fprintf(stderr, "L%d: division by zero\n", line_number),
			exit(EXIT_FAILURE);
	(*next_n).n /= (*current).n;
	free(*stack);
	*stack = next_n;
}
