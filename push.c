#include "monty.h"

/**
 * push - a function that pushes an element to the stack.
 * @stack: the stack
 * @elem: the element we need to push.
 * Return: Nothing.
 */
void push(stack_t **stack, int elem)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = elem;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}

