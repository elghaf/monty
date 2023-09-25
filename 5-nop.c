#include "monty.h"


/**
 * nop - function that does nothing
 *
 * @head: head of the stack
 * @line_num: line number
 * Return: Nothing
 */

void nop(__attribute__((unused))stack_t **head, unsigned int line_num)
{
	(void) (line_num);
}
