#include "monty.h"

#define MAX_LINE_LENGTH 1024

/**
 * free_stack - Frees a stack_t stack.
 * @stack: Pointer to the top of the stack.
 *
 * Return: void
 */
void free_stack(stack_t *stack)
{
	stack_t *tempo;

	while (stack != NULL)
	{
		tempo = stack;
		stack = stack->next;
		free(tempo);
	}
}

/**
 * main - Entry point for the Monty interpreter.
 * @argc: Number of arguments.
 * @argv: Array of arguments.
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int main(int argc, char **argv)
{
	FILE *file_pointer;
	stack_t *stack = NULL;
	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"nop", nop},
		{"swap", swap},
		{NULL, NULL}
	};

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file_pointer = fopen(argv[1], "r");
	if (file_pointer == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	read_file(file_pointer, opcodes, &stack);
	fclose(file_pointer);
	free_stack(stack);

	return (EXIT_SUCCESS);
}

/**
 * read_file - Reads an input file line by line and executes instructions.
 * @file_pointer: The file pointer to the input file.
 * @opcodes: An array of instruction_t structs.
 * @stack: Pointer to the top of the stack.
 *
 * Return: void
 */
void read_file(FILE *file_pointer, instruction_t opcodes[], stack_t **stack)
{
	char line[MAX_LINE_LENGTH];
	unsigned int line_number = 0;
	int i;
	char *opcode;

	while (fgets(line, MAX_LINE_LENGTH, file_pointer) != NULL)
	{
		line_number++;
		opcode = strtok(line, DELIMS);
		if (opcode == NULL || strncmp(opcode, "#", 1) == 0)
			continue;
		for (i = 0; opcodes[i].opcode; i++)
		{
			if (strcmp(opcode, opcodes[i].opcode) == 0)
			{
				opcodes[i].f(stack, line_number);
				break;
			}
		}
		if (opcodes[i].f == NULL)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
			fclose(file_pointer);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
	}
}

