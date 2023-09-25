#include "monty.h"

/**
 * div_fun - function that divide top two elemnt in the stack
 *
 * @head: head of the stack
 * @line_num: line number
 * Return: Nothing
 */
void div_fun(stack_t **head, unsigned int line_num)
{
	stack_t *ptr = *head;
	int num = 0;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_num);
		fclose(arg.textfile);
		free(arg.str);
		free_the_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (ptr->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		fclose(arg.textfile);
		free(arg.str);
		free_the_stack(*head);
		exit(EXIT_FAILURE);
	}
	num = ptr->next->n / ptr->n;
	ptr = ptr->next;
	pop(head, line_num);
	ptr->n = num;
}
