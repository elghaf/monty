#include"monty.h"

/**
 * pop - function removes the top element of the stack
 *
 * @head: head of the stack
 * @line_num: line number
 * Return: Nothing
 */

void pop(stack_t **head, unsigned int line_num)
{
	stack_t *temp;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
		free_the_stack(*head);
		free(arg.str);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	(*head) = (*head)->next;
	free(temp);
}
