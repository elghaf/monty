#include "monty.h"

/**
 * add_top_two_elements - Adds the top two elements of the stack.
 * @stack_head: Pointer to the head of the stack.
 * @line_number: The current line number of the bytecode file.
 *
 * Description:
 * This function adds the top two elements of the stack and replaces
 * the second element with the result. If the stack does not contain
 * at least two elements, it prints an error message.
 */
void add_top_two_elements(stack_t **stack_head, unsigned int line_number)
{
	if (!stack_head || !*stack_head || !(*stack_head)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		error = 1;
		return;
	}

	int result = (*stack_head)->n + (*stack_head)->next->n;
	pop_top_element(stack_head, line_number);
	(*stack_head)->n = result;
}
