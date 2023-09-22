#include "monty.h"

/**
 * print_top_value - Prints the value at the top of the stack.
 * @stack_head: Pointer to the top of the stack.
 * @line_number: The current line number of the Monty bytecodes file.
 *
 * Description:
 * This function prints the value at the top of the stack if the stack is not empty.
 * If the stack is empty, it prints an error message.
 */
void print_top_value(stack_t **stack_head, unsigned int line_number)
{
	if (!stack_head || !*stack_head)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		error = 1;
		return;
	}

	printf("%d\n", (*stack_head)->n);
}
