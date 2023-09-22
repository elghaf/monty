#include "monty.h"

/**
 * swap_top_two_elements - Swaps the top two elements of the stack.
 * @head: A pointer to the top of the stack.
 * @line_number: The current working line number of the Monty bytecodes file.
 *
 * Description:
 * This function swaps the values of the top two elements of the stack.
 */

void swap_top_two_elements(stack_t **head, unsigned int line_number)
{
	int temp;

	if (!head || !*head || !(*head)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		error = 1;
		return;
	}

	temp = (*head)->n;
	(*head)->n = (*head)->next->n;
	(*head)->next->n = temp;
}
