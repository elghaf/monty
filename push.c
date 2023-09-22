#include "monty.h"

/**
 * push_to_stack_or_queue - Pushes a new node to the stack or queue.
 * @stack_head: Pointer to the top of the stack/queue.
 * @line_number: The current line number of the Monty bytecode file.
 * @arg: The argument to push.
 * @mode: 0 for stack, 1 for queue.
 *
 * Description:
 * This function pushes a new node onto the stack or queue based on the specified mode.
 * It also checks if the argument is a valid integer and handles memory allocation errors.
 */
void push_to_stack_or_queue(stack_t **stack_head, unsigned int line_number, char *arg, int mode)
{
	stack_t *new = NULL;
	int num;

	if (!is_valid_integer(arg, &num, line_number))
		return;

	free(arg);
	new = malloc(sizeof(stack_t));

	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		error = 1;
		return;
	}

	new->n = num;

	if (mode == 0)
		stack(stack_head, &new);
	else
		queue(stack_head, &new);
}

/**
 * is_valid_integer - Checks if a string is a valid integer and converts it.
 * @str: The string to check.
 * @num: Pointer to store the converted integer.
 * @line_number: The current line number of the Monty bytecode file.
 * Return: 1 if the string is not a valid integer, 0 otherwise.
 */
int is_valid_integer(char *str, int *num, unsigned int line_number)
{
	int i = 0;
	int sign = 1;

	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}

	if (str[i] == '\0')
	{
		usage_error(line_number);
		return 1;
	}

	while (str[i] != '\0')
	{
		if (isdigit(str[i]))
			i++;
		else
		{
			usage_error(line_number);
			return 1;
		}
	}

	*num = atoi(str) * sign;
	return 0;
}

/**
 * usage_error - Displays a usage error message.
 * @line_number: The current line number of the Monty bytecode file.
 */
void usage_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	error = 1;
}
