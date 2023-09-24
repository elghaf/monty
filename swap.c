#include "monty.h"

/**
 * swap - Swaps top two elem.
 * @stacks: Double pointer to the beginning of the stack.
 * @numbers: The line number files.
 */

void swap(stack_t **stacks, unsigned int numbers)
{
	int nano_nu;

	if (*stacks == NULL || (*stacks)->next == NULL)
	{
		fprintf(stderr, "L%d: Error Swap\n", numbers);
		exit(EXIT_FAILURE);
	}
    else
    {
    nano_nu = (*stacks)->n;
	(*stacks)->n = (*stacks)->next->n;
	(*stacks)->next->n = nano_nu;  
    }
}

