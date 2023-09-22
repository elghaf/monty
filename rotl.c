#include "monty.h"

/**
 * rotate_stack_left - Rotates the stack to the left.
 * The top element of the stack becomes the last one, and the second top element
 * of the stack becomes the first one.
 * @stack_head: Pointer to the top of the stack.
 * @line_number: The current line number of the Monty bytecode file.
 *
 * Description:
 * This function rotates the stack to the left. If there are fewer than two elements
 * on the stack, it does nothing.
 */
void rotate_stack_left(stack_t **stack_head, unsigned int line_number)
{
	int n;
	stack_t *tmp, *new;

	if (!stack_head || !*stack_head || !(*stack_head)->next)
		return;

	if (!((*stack_head)->next)->next)
	{
		swap_top_two_elements(stack_head, line_number);
		return;
	}

	n = (*stack_head)->n;
	pop_top_element(stack_head, line_number);

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		error = 1;
		return;
	}

	new->n = n;
	new->next = NULL;
	tmp = *stack_head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}
