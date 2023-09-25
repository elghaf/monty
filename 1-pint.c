#include "monty.h"

/**
 * Top_Of_Stack - function that prints the top of the stack
 *
 * @head: head of the stack
 * @line_num: line number
 * Return: Nothing
 */

void Top_Of_Stack(stack_t **head, unsigned int line_num)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
		fclose(arg.textfile);
		free_the_stack(*head);
		free(arg.str);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
