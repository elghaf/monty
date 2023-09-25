#include "monty.h"

/**
 * mul_fun - function that mul the top two elements in the stack
 *
 * @head: head of the stack
 * @line_num: line number
 * Return: Nothing
 */
void mul_fun(stack_t **head, unsigned int line_num)
{
	stack_t *ptr = *head;
	int num = 0;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_num);
		fclose(arg.textfile);
		free(arg.str);
		free_the_stack(*head);
		exit(EXIT_FAILURE);
	}
	num = ptr->next->n * ptr->n;
	ptr = ptr->next;
	pop(head, line_num);
	ptr->n = num;
}
