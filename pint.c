#include "monty.h"

/**
 * pint - Prints the value at the top of the stack, followed by a newline.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: The line number in the Monty bytecode file.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free(data);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
