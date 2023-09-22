#include "monty.h"

/**
 * print_stack - Prints all elements of the stack.
 * @stack_head: Pointer to the top of the stack.
 * @line_number: The current line number of the Monty bytecodes file.
 *
 * Description:
 * This function prints all elements of the stack in order from top to bottom.
 */

void print_stack(stack_t **stack_head, unsigned int line_number)
{
	stack_t *current = *stack_head;

	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
