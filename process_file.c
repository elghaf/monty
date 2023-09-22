#include "monty.h"

/**
 * process_file - Process the lines of the file.
 * @file: Pointer to the file to process.
 *
 * Return: 0 on sucess, 1 on failure.
 */

int process_file(FILE *file)
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 0;
	char *opcode;
	ssize_t read;

	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
		opcode = strtok(line, "\n\t\r");

		if (opcode == NULL || opcode[0] == '#')
			continue;

		if (strcmp(opcode, "push") == 0)
			push(&stack, line_number);
		else if (strcmp(opcode, "pall") == 0)
			pall(&stack, line_number);
		else
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
			free(line);
			fclose(file);
			exit(EXIT_FAILURE);
		}
	}

	free(line);
	fclose(file);
	return (0);
}
