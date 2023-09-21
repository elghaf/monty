#include "monty.h"

/**
 * divide_top_two_elements - Divides the second top element by the top element of the stack.
 * @stack_head: A pointer to the top of the stack.
 * @line_number: The current line number of the bytecode file.
 *
 * Description:
 * This function divides the second top element of the stack by the top element
 * and replaces the second top element with the result. If the stack is too short
 * or if division by zero is attempted, it prints corresponding error messages.
 */
void divide_top_two_elements(stack_t **stack_head, unsigned int line_number)
{
	int quotient = 0;

	if (!stack_head || !*stack_head || !(*stack_head)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		error = 1;
		return;
	}

	if ((*stack_head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		error = 1;
		return;
	}

	quotient = ((*stack_head)->next->n) / ((*stack_head)->n);
	pop_top_element(stack_head, line_number);
	(*stack_head)->n = quotient;
}
