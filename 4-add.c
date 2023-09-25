#include "monty.h"

/**
 * add - function that adds top two elemnt in the stack
 *
 * @head: head of the stack
 * @line_num: line number
 * Return: Nothing
 */
void add(stack_t **head, unsigned int line_num)
{
	stack_t *ptr = *head;
	int sum = 0;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		fclose(arg.textfile);
		free(arg.str);
		free_the_stack(*head);
		exit(EXIT_FAILURE);
	}
	sum = ptr->n + ptr->next->n;
	ptr = ptr->next;
	pop(head, line_num);
	ptr->n = sum;
}

