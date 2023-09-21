#include "monty.h"

/**
 * line_tok - Gets the line from the monty file and tokenizes it.
 * @head: The head of the linked list
 * @fp: File pointer
 * @line: Line from the monty file to tokenize
 * @line_number: The current working line number of the Monty bytecodes file
 * @mode: 0 if stack, 1 if queue
 * Return: void
 */
void line_tok(stack_t **head, FILE *fp, char *line,
unsigned int line_number, int *mode)
{
	char *token = NULL;
	int mode_changed = 0;

	token = strtok(line, " \n");
	while (token && token[0] == ' ')
		token = strtok(NULL, " \n");
	if (!token)
		return;
	mode_changed = check_mode(token, mode);
	if (mode_changed)
		return;
	check_token(head, fp, line, token, line_number, mode);
}
/**
 * check_mode - Checks if the mode has been changed to stack or queue
 * @token: The word to check
 * @mode: 0 if stack, 1 if queue
 * Return: 1 if changed, 0 if not changed
 */
int check_mode(char *token, int *mode)
{
	if (!strncmp(token, "stack", 5) &&
			(token[5] == '\0' || token[5] == ' ' || token[5] == '\n'))
	{
		*mode = 0;
		return (1);
	}
	if (!strncmp(token, "queue", 5) &&
			(token[5] == '\0' || token[5] == ' ' || token[5] == '\n'))
	{
		*mode = 1;
		return (1);
	}
	return (0);
}
