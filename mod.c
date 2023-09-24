#include "monty.h"

/**
 * mod - division of the second top element
 *       of the stack by the top element.
 * @stack: Double pointer of the stack beg.
 * @lines: The line number bytecode file.
 */

void mod(stack_t **stack, unsigned int lines)
{
	stack_t *temperature;

	if ((!*stack) || (!(*stack)->next))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", lines);
		exit(EXIT_FAILURE);
	}
	temperature = *stack;
	if (temperature->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", lines);
		exit(EXIT_FAILURE);
	}
	temperature->next->n = temperature->next->n % temperature->n;
	pop(stack, lines);
}
