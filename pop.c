#include "monty.h"

/**
 * pop - print top
 * @head: head of our stack
 * @numbers: number of count
 * Return: no return
 */
void pop(stack_t **head, UUU numbers)
{
	stack_t *copyr;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", numbers);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	copyr = *head;
	*head = copyr->next;
	free(copyr);
}