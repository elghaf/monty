#include "monty.h"

/**
 * pchar_fun - function that prints the top of the stack
 *
 * @head: head of the stack
 * @line_num: line number
 * Return: Nothing
 */

void pchar_fun(stack_t **head, unsigned int line_num)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
		fclose(arg.textfile);
		free_the_stack(*head);
		free(arg.str);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n > 127 || (*head)->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
		fclose(arg.textfile);
		free(arg.str);
		free_the_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*head)->n);
}
