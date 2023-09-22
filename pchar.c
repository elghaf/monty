#include "monty.h"

/**
 * print_top_char - Prints the character at the top of the stack.
 * @stack_head: Pointer to the top of the stack.
 * @line_number: The current line number of the Monty bytecodes file.
 *
 * Description:
 * This function prints the character at the top of the stack if it's a valid
 * printable ASCII character (from 32 to 126). Otherwise, it prints an error message.
 */
void print_top_char(stack_t **stack_head, unsigned int line_number)
{
	int n;

	if (!stack_head || !*stack_head)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		error = 1;
		return;
	}

	n = (*stack_head)->n;

	if (!(n >= 32 && n <= 126))
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		error = 1;
		return;
	}

	putchar(n);
	putchar('\n');
}
