#include "monty.h"
/**
 * check_comment - Check if a line is a comment.
 * @line : Pointer to string.
 * Return: 1 if comment, 0 if not.
 */
int check_comment(char *line)
{
	int result = 1;

	while (*line != '\0' && *line != '#')
	{
		if (*line != ' ')
			result = 0;
		line++;
	}
	return (result);
}
