#include "monty.h"
/**
 * is_Number - Number to check.
 * @arg: The string that has to check.
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
 * push - Push l_num to the stack.
 * @stack_beg: A pointer to the top of the stack.
 * @l_num: The line number in the Monty file where push was called.
 */
void push(stack_t **stack_beg, unsigned int l_num)
{
	char *first_args = data[1];
	int val, is_Negative;
	stack_t *copy_stack;

	if (!first_args)
	{
		fprintf(stderr, "L%u: usage: push integer\n", l_num);
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
		fprintf(stderr, "L%u: usage: push integer\n", l_num);
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
		if (!*stack_beg)
			*stack_beg = copy_stack;
		else
		{
			copy_stack->next = *stack_beg;
			(*stack_beg)->prev = copy_stack;
			*stack_beg = copy_stack;
		}
	}
	else if (dtada == QUEUE)
	{
		stack_t *temp = *stack_beg;

		if (!temp)
		{
			*stack_beg = copy_stack;
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
 * @stack_beg: Double pointer of the head stack.
 * @line_number: The line number of files.
 */
void pall(stack_t **stack_beg, unsigned int l_num)
{
	stack_t *cc;
	(void)l_num;


	if (stack_beg == NULL)
		return;

	cc = *stack_beg;

	while (cc)
	{
		printf("%d\n", cc->n);
		cc = cc->next;
	}
}
