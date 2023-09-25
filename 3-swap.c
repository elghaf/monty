#include "monty.h"

/**
 * swap - function that swaps two elements of the stack
 *
 * @head: head of the stack
 * @line_num: line number
 *
 * Return: Nothing
 */

void swap(stack_t **head, unsigned int line_num)
{
	stack_t *ptr = *head;
	int temp;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		fclose(arg.textfile);
		free(arg.str);
		free_the_stack(*head);
		exit(EXIT_FAILURE);
	}
	ptr = *head;
	temp = ptr->n;
	ptr->n = ptr->next->n;
	ptr->next->n = temp;
}

