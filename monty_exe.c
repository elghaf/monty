#include "monty.h"

/**
 * files_name - function that execute the  instruction.
 * @instr: the instruction.
 * @line_number: the line.
 * Return: Nothing.
 */
void files_name(char *instr, unsigned int line_number)
{
	char *opcode, *arg;
	stack_t *stack = NULL;

	opcode = strtok(instr, " \t\n");
	if (opcode)
	{
		arg = strtok(NULL, " \t\n");
		if (strcmp(opcode, "push") == 0)
		{
			if (!arg)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
			push(&stack, atoi(arg));
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall(&stack, line_number);
		}
		else if (strcmp(opcode, "pop") == 0)
		{
			pop(&stack, line_number);
		}
		else if (strcmp(opcode, "pint") == 0)
		{
			pint(&stack, line_number);
		}
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
	}
}

