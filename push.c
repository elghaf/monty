#include "monty.h"

/**
 * check_validint - fucntion check if a valid integer
 *
 * @num: string containing interger
 * Return: 0 or 1
 */
int check_validint(char *num)
{
	unsigned int i = 0;

	if (num[i] == '-')
		i++;

	while (num[i])
	{
		if (!(num[i] >= 48 && num[i] <= 58))
		{
			return (0);
		}
		i++;
	}
	return (1);
}


/**
 * Push_To_Stack - function to push to the stack
 *
 * @head: head of the stack
 * @line_num: line number
 * Return: Nothing
 */

void Push_To_Stack(stack_t **head, unsigned int line_num)
{
	stack_t *temp;
	int f, n;

	temp = malloc(sizeof(stack_t));
	if (temp == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (arg.num == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
		fclose(arg.textfile);
		free_the_stack(*head);
		exit(EXIT_FAILURE);
	}
	f = check_validint(arg.num);
	if (f == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
		fclose(arg.textfile);
		free_the_stack(*head);
		exit(EXIT_FAILURE);
	}
	n = atoi(arg.num);
	temp->n = n, temp->next = NULL, temp->prev = NULL;
	if (*head == NULL)
	{
		*head = temp;
	}
	else
	{
		temp->next = *head;
		(*head)->prev = temp;
		*head = temp;
	}
}

/**
 * Print_Stack - function prints values in the stack
 *
 * @head: head of the stack
 * @line_num: line number
 *
 * Return: Nothing
 */

void Print_Stack(stack_t **head, __attribute__((unused))unsigned int line_num)
{
	const stack_t *ptr = *head;
	size_t n = 0;

	while (ptr)
	{
		printf("%d\n", ptr->n);
		n++;
		ptr = ptr->next;
	}
}

