#include "monty.h"
/**
 * pchar -  prints the char at the top of the stack, followed by a new line.
 * @stack : Top of stack.
 * @line_number : The number of the line in .m file.
 * Return: Void.
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (len_stack(stack) == 0)
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number)
		, exit(EXIT_FAILURE);
	if (!((*current).n >= 0 && (*current).n <= 127))
		fprintf(stderr, "L%d: can't pchar, value out of range\n",
		line_number), exit(EXIT_FAILURE);
	printf("%c\n", (*current).n);
}
