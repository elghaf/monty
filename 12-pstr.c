#include "monty.h"

/**
 * pstr_fun - function that prints the string starting
 * at the top of the stack
 *
 * @head: head of the stack
 * @line_num: line number
 * Return: Nothing
 */
void pstr_fun(stack_t **head, __attribute__((unused))unsigned int line_num)
{
	stack_t *ptr = *head;

	while (ptr != NULL)
	{
		if (ptr->n > 127 || ptr->n <= 0)
			break;
		printf("%c", ptr->n);
		ptr = ptr->next;
	}
	printf("\n");
}
