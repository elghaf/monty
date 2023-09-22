#include "monty.h"

/**
 * subtract_top_elements - Subtracts the top element of the stack from the second element.
 * @head: A pointer to the top of the stack.
 * @line_number: The current working line number of the Monty bytecodes file.
 *
 * Description:
 * This function subtracts the top element of the stack from the second element
 * and stores the result in the new top element of the stack.
 */
void subtract_top_elements(stack_t **head, unsigned int line_number)
{
	int result = 0;

	if (!head || !*head || !(*head)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		error = 1;
		return;
	}

	result = ((*head)->next->n) - ((*head)->n);
	_pop(head, line_number);
	(*head)->n = result;
}
