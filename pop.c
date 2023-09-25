#include "monty.h"

/**
 * pop - a fucntion that  removes the top element of the stack.
 * @stack: the stack.
 * @line_number: the number of line for error handling.
 * Return: Nothing.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}

