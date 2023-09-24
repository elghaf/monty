#include "monty.h"

/**
 * swap - Swaps top two elem.
 * @stack_beg: Double pointer to the beginning of the stack.
 * @l_num: The line number files.
 */

void swap(stack_t **stack_beg, unsigned int l_num)
{
	int nano_nu;

	if (*stack_beg == NULL || (*stack_beg)->next == NULL)
	{
		fprintf(stderr, "L%d: Error Swap\n", l_num);
		exit(EXIT_FAILURE);
	}
    else
    {
    nano_nu = (*stack_beg)->n;
	(*stack_beg)->n = (*stack_beg)->next->n;
	(*stack_beg)->next->n = nano_nu;  
    }
}

