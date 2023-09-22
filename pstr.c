#include "monty.h"

/**
 * print_string_from_stack - Prints the string starting at the top of the stack.
 * @stack_head: Pointer to the top of the stack.
 * @line_number: The current line number of the Monty bytecode file.
 *
 * Description:
 * This function prints the string starting at the top of the stack, where each
 * element represents a character in the ASCII range [32, 126]. It stops printing
 * when it encounters a zero element or a value outside the ASCII range.
 */
void print_string_from_stack(stack_t **stack_head, unsigned int line_number)
{
	int n;
	stack_t *current = *stack_head;

	(void)line_number;

	while (current)
	{
		n = current->n;

		if (n == 0 || !(n >= 32 && n <= 126))
			break;

		putchar(n);
		current = current->next;
	}

	putchar('\n');
}
