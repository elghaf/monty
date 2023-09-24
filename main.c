#include "monty.h"
#include <stdio.h>

/**
 * main - main function
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, 1 otherwise
 */

bus_t bus = {NULL, NULL, NULL};

int main(int argc, char **argv)
{
	FILE *file;
	char *content = NULL;
	stack_t *stack = NULL;
	unsigned int count = 1;
	size_t size = 0;
	ssize_t read = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	bus.file = file;
	while (read > 0)
	{
		if (content)
		{
			free(content);
			content = NULL;
		}
		read = _getline(&content, &size, file);
		bus.content = content;
		if (read < 0)
		{
			free(content);
			break;
		}
		execute(&stack, count, file, content);
		count++;
	}
	free_stack(stack);
	fclose(file);
	return (0);

}
