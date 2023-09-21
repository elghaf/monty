#include "monty.h"

int error = 0;

/**
 * main - The entry point of the Monty Interpreter
 * @ac: The argument number
 * @av: The argument string/array
 * Return: int
 */
int main(int ac, char **av)
{
	FILE *fp;
	char *line = NULL;
	size_t size = 0;
	stack_t *head = NULL;
	int line_number = 0;
	int mode = 0;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(av[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &size, fp) != -1)
	{
		line_number++;
		line_tok(&head, fp, line, line_number, &mode);
	}
	free_list(&head, fp, line);
	exit(EXIT_SUCCESS);
}
