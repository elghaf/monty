#include "monty.h"
/**
 * is_Number - Number to check.
 * @check_numb: The string that has to check.
 *
 * Return: 1 if number, 0 otherwise.
 */
int is_Number(char *check_numb)
{
	int check;

	for (check = 0; check_numb[check]; check++)
	{
		if (!isdigit(check_numb[check]))
			return (0);
	}
	return (1);
}

/**
 * push - Push numbers to the stack.
 * @stacks: A pointer to the top of the stack.
 * @numbers: The line number in the Monty file where push was called.
 */
void push(stack_t **stacks, unsigned int numbers)
{
	char *first_args = data[1];
	int val, is_Negative;
	stack_t *copy_stack;

	if (!first_args)
	{
		fprintf(stderr, "L%u: usage: push integer\n", numbers);
		exit(EXIT_FAILURE);
	}
	is_Negative = 0;
	if (first_args[0] == '-')
	{
		is_Negative = 1;
		first_args++;
	}
	if (!is_Number(first_args))
	{
		fprintf(stderr, "L%u: usage: push integer\n", numbers);
		exit(EXIT_FAILURE);
	}
	val = atoi(first_args);
	if (is_Negative)
		val = -val;
	copy_stack = malloc(sizeof(stack_t));

	if (copy_stack == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	copy_stack->prev = NULL;
	copy_stack->n = val;
	copy_stack->next = NULL;

	if (dtada == STACK)
	{
		if (!*stacks)
			*stacks = copy_stack;
		else
		{
			copy_stack->next = *stacks;
			(*stacks)->prev = copy_stack;
			*stacks = copy_stack;
		}
	}
	else if (dtada == QUEUE)
	{
		stack_t *temp = *stacks;

		if (!temp)
		{
			*stacks = copy_stack;
		}
		else
		{
			while (temp->next)
				temp = temp->next;
			temp->next = copy_stack;
			copy_stack->prev = temp;
		}
	}
}

/**
 * pall - Print the val of the stack.
 * @stacks: Double pointer of the head stack.
 * @numbers: The line number of files.
 */
void pall(stack_t **stacks, unsigned int numbers)
{
	stack_t *cc;
	(void)numbers;

	if (stacks == NULL)
		return;
	cc = *stacks;
	while (cc)
	{
		printf("%d\n", cc->n);
		cc = cc->next;
	}
}
