#include "monty.h"

/**
 * free_stack - Frees the entire stack and associated resources.
 * @stack_head: A pointer to the top of the stack.
 * @file_ptr: File pointer to the bytecode file.
 * @line_buffer: Buffer for reading lines from the file.
 *
 * Description:
 * This function frees the entire stack and any associated resources, such as
 * the file pointer and line buffer. It iterates through the stack elements
 * and deallocates memory for each node.
 */
void free_stack(stack_t **stack_head, FILE *file_ptr, char *line_buffer)
{
	if (*stack_head != NULL)
	{
		while ((*stack_head)->next != NULL)
		{
			*stack_head = (*stack_head)->next;
			free((*stack_head)->prev);
		}
		free(*stack_head);
	}

	if (file_ptr != NULL)
		fclose(file_ptr);

	if (line_buffer != NULL)
		free(line_buffer);
}
