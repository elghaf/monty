#include "monty.h"

/**
 * rotate_stack_right - Rotates the stack to the right.
 * The last element of the stack becomes the top one, and the top element of
 * the stack becomes the second top one.
 * @stack_head: Pointer to the top of the stack.
 * @line_number: The current line number of the Monty bytecode file.
 *
 * Description:
 * This function rotates the stack to the right. If there are fewer than two elements
 * on the stack, it does nothing.
 */
void rotate_stack_right(stack_t **stack_head, unsigned int line_number)
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

	tmp = *stack_head;
	while (tmp->next)
		tmp = tmp->next;
	n = tmp->n;
	(tmp->prev)->next = NULL;
	free(tmp);

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = n;
	(*stack_head)->prev = new;
	new->next = *stack_head;
	new->prev = NULL;
	*stack_head = new;
}
