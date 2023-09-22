#include "monty.h"

/**
 * push - Pushes an element to the stack.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: Line number in file.
 */

void push(stack_t **stack, unsigned int line_number)
{
	char *arg = strtok(NULL, " \n\t\r");
	int n;
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!arg || (*arg != '-' && !isdigit(*arg)))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	n = atoi(arg);

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;
}


