#include "monty.h"

/**
 * execute_instruction - Executes a Monty bytecode instruction.
 * @head: Pointer to the top of the stack.
 * @fp: File pointer.
 * @line: Line from the Monty file.
 * @token: Tokenized instruction.
 * @line_number: The current working line number of a Monty bytecode file.
 * @mode: 0 if stack, 1 if queue.
 *
 * Description:
 * This function executes a Monty bytecode instruction based on the provided token.
 * It handles push instructions, unknown instructions, and opcode execution.
 */
void execute_instruction(stack_t **head, FILE *fp, char *line, char *token, unsigned int line_number, int *mode)
{
	if (is_push_instruction(token))
	{
		char *push_arg = extract_push_arg(token, line_number);
		if (push_arg != NULL)
		{
			_push(head, line_number, push_arg, mode);
			free(push_arg);
			if (error == 1)
			{
				free_list(head, fp, line);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			free_list(head, fp, line);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		void (*function)(stack_t **, unsigned int) = get_function(token);
		if (!function)
		{
			opcode_fail(token, line_number);
			if (error == 1)
			{
				free_list(head, fp, line);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			function(head, line_number);
			if (error == 1)
			{
				free_list(head, fp, line);
				exit(EXIT_FAILURE);
			}
		}
	}
}

/**
 * is_push_instruction - Checks if a token is a push instruction.
 * @token: Token to check.
 * Return: 1 if the token is a push instruction, 0 otherwise.
 */
int is_push_instruction(char *token)
{
	return (strncmp("push", token, 4) == 0 && (token[4] == '\0' || token[4] == ' ' || token[4] == '\n'));
}

/**
 * extract_push_arg - Extracts the argument from a push instruction.
 * @token: Token containing the push instruction.
 * @line_number: The current working line number of a Monty bytecode file.
 * Return: On success, returns a pointer to the argument.
 *         On failure, returns NULL.
 */
char *extract_push_arg(char *token, unsigned int line_number)
{
	char *push_arg;
	char *token_copy;
	int len;

	if (token[4] == '\0' || token[4] == '\n')
	{
		usage_error(line_number);
		return (NULL);
	}

	token_copy = strdup(token);
	if (!token_copy)
	{
		fprintf(stderr, "Error: malloc failed\n");
		error = 1;
		return (NULL);
	}

	push_arg = strtok(token_copy + 4, " \n");
	if (!push_arg)
	{
		usage_error(line_number);
		free(token_copy);
		return (NULL);
	}

	len = strlen(push_arg);
	if (is_valid_integer(push_arg, len, line_number))
	{
		free(token_copy);
		return (NULL);
	}

	return (push_arg);
}

/**
 * is_valid_integer - Checks if a string is a valid integer.
 * @str: The string to check.
 * @len: The length of the string.
 * @line_number: The current working line number of a Monty bytecode file.
 * Return: 1 if the string is not a valid integer, 0 otherwise.
 */
int is_valid_integer(char *str, int len, unsigned int line_number)
{
	int i = 0;
	int sign = 1;

	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}

	if (str[i] == '\0')
	{
		usage_error(line_number);
		return 1;
	}

	while (i < len)
	{
		if (!isdigit(str[i]))
		{
			usage_error(line_number);
			return 1;
		}
		i++;
	}

	return 0;
}

/**
 * usage_error - Displays a usage error message.
 * @line_number: The current line number of the Monty bytecode file.
 */
void usage_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	error = 1;
}

/**
 * get_function - Matches an opcode with its corresponding function.
 * @token: Token to match.
 * Return: A pointer to the matching function.
 */
void (*get_function(char *token))(stack_t **, unsigned int)
{
	int i;
	instruction_t ops[] = {
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{NULL, NULL}
	};

	if (token[0] == '#')
		return (_nop);

	for (i = 0; ops[i].opcode; i++)
	{
		if (strcmp(token, ops[i].opcode) == 0)
			return (ops[i].f);
	}

	return (NULL);
}

/**
 * opcode_fail - Prints a message for an unknown instruction.
 * @token: The invalid command to display.
 * @line_number: Line number in Monty bytecode file where error occurred.
 */
void opcode_fail(char *token, unsigned int line_number)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
	error = 1;
}
