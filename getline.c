#include "monty.h"

/**
 * tokenize_and_process_line - Tokenizes and processes a line from the Monty file.
 * @stack_head: The head of the linked list (stack).
 * @file_ptr: File pointer to the Monty bytecode file.
 * @line_buffer: Line from the Monty file to tokenize.
 * @line_number: The current line number of the Monty bytecodes file.
 * @execution_mode: 0 if stack mode, 1 if queue mode.
 *
 * Description:
 * This function tokenizes a line from the Monty file and processes it based on
 * the execution mode (stack or queue). It also handles mode-changing commands.
 */
void tokenize_and_process_line(stack_t **stack_head, FILE *file_ptr, char *line_buffer,
                               unsigned int line_number, int *execution_mode)
{
	char *token = NULL;
	int mode_changed = 0;

	token = strtok(line_buffer, " \n");
	while (token && token[0] == ' ')
		token = strtok(NULL, " \n");

	if (!token)
		return;

	mode_changed = check_mode(token, execution_mode);

	if (mode_changed)
		return;

	process_token(stack_head, file_ptr, line_buffer, token, line_number, execution_mode);
}

/**
 * check_mode - Checks if the mode has been changed to stack or queue.
 * @token: The word to check for mode change.
 * @execution_mode: Pointer to the execution mode (0 if stack, 1 if queue).
 * Return: 1 if mode changed, 0 if not changed.
 */
int check_mode(char *token, int *execution_mode)
{
	if (!strncmp(token, "stack", 5) &&
			(token[5] == '\0' || token[5] == ' ' || token[5] == '\n'))
	{
		*execution_mode = 0;
		return (1);
	}

	if (!strncmp(token, "queue", 5) &&
			(token[5] == '\0' || token[5] == ' ' || token[5] == '\n'))
	{
		*execution_mode = 1;
		return (1);
	}

	return (0);
}
