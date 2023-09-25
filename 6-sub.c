#include "monty.h"

/**
 * sub - function that subtracts the top two elements in the stack
 *
 * @head: head of the stack
 * @line_num: line number
 * Return: Nothing
 */
void sub(stack_t **head, unsigned int line_num)
{
	stack_t *ptr = *head;
	int diff = 0;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_num);
		fclose(arg.textfile);
		free(arg.str);
		free_the_stack(*head);
		exit(EXIT_FAILURE);
	}
	diff = ptr->next->n - ptr->n;
	(*head) = (*head)->next;
	free(ptr);
	(*head)->n = diff;
}
