#include "monty.h"
/**
 * push - adds a new node at the beginning of the stack.
 * @stack : Pointer to Pointer to top of stack.
 * @line_number : Number of the line in .m file.
 * Return: Void.
 */
void push(stack_t **stack, unsigned int line_number
		__attribute__((unused)))
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		fprintf(stderr, "Error: malloc failed\n"), exit(EXIT_FAILURE);
	(*new).n = n;
	if (*stack == NULL)
	{
		(*new).next = NULL;
		(*new).prev = NULL;
		*stack = new;
		return;
	}
	(*new).next = *stack;
	(**stack).prev = new;
	(*new).prev = NULL;
	*stack = new;
}
