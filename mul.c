#include "monty.h"

/**
 * multiply_top_two_elements - Multiplies the second top element of the stack
 *                             with the top element.
 * @stack_head: Pointer to the top of the stack.
 * @line_number: The current line number of the Monty bytecode file.
 *
 * Description:
 * This function multiplies the second top element of the stack with the top element
 * and replaces the second top element with the result. If the stack is too short,
 * it prints an error message.
 */
void multiply_top_two_elements(stack_t **stack_head, unsigned int line_number)
{
	int result = 0;

	if (!stack_head || !*stack_head || !(*stack_head)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		error = 1;
		return;
	}

	result = ((*stack_head)->next->n) * ((*stack_head)->n);
	pop_top_element(stack_head, line_number);
	(*stack_head)->n = result;
}
