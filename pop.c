#include "monty.h"

/**
 * pop_top_element - Removes the top element of the stack.
 * @stack_head: Pointer to the top of the stack.
 * @line_number: The current line number of the Monty bytecode file.
 *
 * Description:
 * This function removes the top element of the stack. If the stack is empty,
 * it prints an error message.
 */
void pop_top_element(stack_t **stack_head, unsigned int line_number)
{
	stack_t *tmp;

	if (!stack_head || !*stack_head)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		error = 1;
		return;
	}

	tmp = *stack_head;

	if (tmp->next)
	{
		(tmp->next)->prev = NULL;
		*stack_head = tmp->next;
	}
	else
	{
		*stack_head = NULL;
	}

	free(tmp);
}
