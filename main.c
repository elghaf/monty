#include "monty.h"

/**
 * main - This is the entry point of a program
 * @ac: This is the number of arguments at the start of the program
 * @av: This is the array of characters at the start of the program
 * Return: Always 0 success
 */
int main(int ac, char *av[])
{
	char *s = NULL, *buffer, *op_arr[2];
	stack_t *h = NULL;
	size_t buffersize = 1024, num_line = 0;
	ssize_t line_put;
	void (*func_op)(stack_t **staues, unsigned int count_line);

	if (ac != 2)
		fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
	file = fopen(av[1], "r");
	if (file == NULL)
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
	exit(EXIT_FAILURE);
	while (1)
	{
		line_put = getline(&s, &buffersize, file);
		if (line_put == -1)
			break;
		num_line++;
		op_arr[0] = strtok(s, "\n ");
		if (op_arr[0] == NULL)
			opcode_nop(&h, num_line);
		else if (strcmp("push", op_arr[0]) == 0)
		{
			buffer = strtok(NULL, "\n ");
				if (buffer != NULL)
				{
					opcode_push(&h, num_line); }
		} else if (op_arr[0] != NULL && op_arr[0][0] != '#')
		{
			func_op = op(op_arr[0], num_line, &h);

			if (func_op == NULL && num_line == 0)
			{
				fprintf(stderr, "L%ld: unknown instruction %s\n",
					num_line, op_arr[0]);
				exit(EXIT_FAILURE);
			} func_op(&h, num_line); }
	} fclose(file), free(s), monty_free(h);
	return (0); }
