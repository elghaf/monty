#include "monty.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
* main - monty program
* @argc: number of arguments
* @argv: array of arguments from cmd line
* Return: 0 on success or exit failure
*/
int main(int argc, char **argv)
{
	FILE *fd = NULL;
	stack_t *stack = NULL;
	char *line = NULL;
	size_t line_size = 0;

	if (argc == 2)
	{
		if (access(argv[1], F_OK) == -1)
		{
			fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
			exit(EXIT_FAILURE);
		}
		else
		{
			fd = fopen(argv[1],"r");
			while (getline(&line, &line_size, fd) != -1)
				execute_cmd(&stack, &line, &fd); 
			free(line);
			fclose(fd);
			free_stack(&stack);
		}
	}
	else
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
