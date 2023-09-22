#include "monty.h"
/**
* pall - print all node in stack
* @stack: the stack
* @line_number: line number but it is voided
*/
void pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	stack_t *current = *stack;

	while(current != NULL)
	{
		printf("%u\n", current->n);
		current = current->next;
	}
}
/**
* add_node - creates a new node
* @top: the address of the top node in a stack
* @n: value of the element
* Return: node on success or NULL on failure
*/
stack_t *add_node(stack_t **top, int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (top == NULL || new_node == NULL)
		return NULL;

	new_node->n = n;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}
/**
* push - pushes a element into the stack
* @stack: pointer to the top most stact item
* @line_number: the current line in the monty file
*/
void push(stack_t **stack, unsigned int line_number)
{
	int val = 0;
	stack_t *n_node = NULL;
	char *op_valarg = strtok( NULL, " \n\t");

	val = atoi(op_valarg);
	if ((!val && (strcmp(op_valarg,"0") && strcmp(op_valarg, "-0")) || !op_valarg))
	{
		fprintf(stderr ,"L%u: usage: push integer\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	n_node = add_node(stack, val);
	if (*stack != NULL)
	{
		n_node->next = *stack;
		(*stack)->prev = n_node;
	}

	*stack = n_node;
}

