#include "monty.h"
/**
 * opcode_push - This is a program that pushes an element to stack
 * @stack: This is the stack that an element would be pushed to
 * @line_number: This is the number of lines
 */
void opcode_push(stack_t **stack, unsigned int line_number)
{
	char *buffer;

	stack_t *stack_item;

	buffer = strtok(NULL, "\n ");

	if (buffer == NULL || _isdigit(buffer) == 1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(file);
		monty_free(*stack);
		exit(EXIT_FAILURE);

		if (_isdigit(buffer) == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(file);
			monty_free(*stack);
			exit(EXIT_FAILURE);
		}
	}
	stack_item = malloc(sizeof(stack_t));
	if (stack_item == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(file);
		exit(EXIT_FAILURE);
	}
	stack_item->n = atoi(buffer);
	stack_item->next = NULL;
	stack_item->prev = NULL;
	if (*stack != NULL)
	{
		stack_item->next = *stack;
		(*stack)->prev = stack_item;
		*stack = stack_item;
	}
	*stack = stack_item;
}

/**
 * _isdigit - This program checks if a string is an integer
 * @string: This is the string to be checked
 * Return: 1 if the string is an integer otherwise return 0
 */
int _isdigit(char *string)
{
	int num = 0;

	if (string[num] == '-')
	{
		num++;
	}
	while (string[num] != '\0')
	{
		if (!isdigit(string[num]))
		{
			return (1);
		}
		num++;
	}

	return (0);
}

#include "monty.h"

/**
 * opcode_pall - This program prints all the values on the stack,
 * starting from the top of the stack
 * @stack: This is a pointer to pointer at the head of a stack
 * @count_line: This i s an integer that shows where the commandappear
 */
void opcode_pall(stack_t **stack, unsigned int count_line)
{
	stack_t *ptr;

	(void) count_line;

	ptr = *stack;

	while (ptr)
	{
		printf("%d", ptr->n);
		ptr = ptr->next;
		printf("\n");
	}
}
