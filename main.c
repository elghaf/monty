#include "monty.h"
stack_t *stack = NULL;

/**
 * main - Entry point of the program
 * @argc: Number of command line arguments
 * @argv: Array of command line argument strings
 * Return: Always returns 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_and_parse_file(argv[1]);
	free_stack();
	return (0);
}

/**
 * create_node - Creates a new stack node
 * @value: Value to be stored in the new node
 * Return: A pointer to the newly created node, or NULL on failure
 */
stack_t *create_node(int value)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		exit(EXIT_FAILURE);

	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->n = value;
	return (new_node);
}

/**
 * free_stack - Frees all nodes in the stack
 */
void free_stack(void)
{
	stack_t *current_node;

	if (stack == NULL)
		return;

	while (stack != NULL)
	{
		current_node = stack;
		stack = stack->next;
		free(current_node);
	}
}

/**
 * add_to_stack - Adds a new node to the top of the stack
 * @new_node: Pointer to the new node
 * @line_number: Line number where the opcode appears
 */
void add_to_stack(stack_t **new_node, __attribute__((unused)) unsigned int line_number)
{
	stack_t *temp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);

	if (stack == NULL)
	{
		stack = *new_node;
		return;
	}

	temp = stack;
	stack = *new_node;
	(*new_node)->next = temp;
	temp->prev = *new_node;
}
