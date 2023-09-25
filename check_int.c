#include "monty.h"
/**
 * check_int - Check if a string is an integer.
 * @string : Pointer to string to be checked.
 * Return: 1 if integer, 0 if not.
 */
int check_int(char *string)
{
	int result = 1;

	if (*string == '-')
		string++;
	while (*string != '\0')
	{
		if (!(*string >= 48 && *string <= 57))
		{
			result = 0;
			break;
		}
		string++;
	}
	return (result);
}
