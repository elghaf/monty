#include "monty.h"
/**
 * check_space - Check if a string has only spaces.
 * @string : Pointer to string.
 * Return: 1 if the string has only spaces, 0 if not.
 */
int check_space(char *string)
{
	int result = 1;

	while (*string != '\0')
	{
		if (*string != ' ' && *string != '\n')
		{
			result = 0;
			break;
		}
		string++;
	}
	return (result);
}
