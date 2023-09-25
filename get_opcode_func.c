#include "monty.h"
/**
 * gof - Get the function of the opcode.
 * @command : Pointer to command.
 * @line_number : Number of the line in .m file.
 * Return: Pointer to function.
 */
void (*gof(char *command, unsigned int line_number))(stack_t **, unsigned int)
{
	int i = 0;

	instruction_t opcodes[] = {
			{"push", push},
			{"pall", pall},
			{"pint", pint},
			{"pop", pop},
			{"swap", swap},
			{"add", add},
			{"nop", nop},
			{"sub", sub},
			{"div", division},
			{"mul", mul},
			{"mod", mod},
			{"pchar", pchar},
			{"pstr", pstr},
			{"rotl", rotl},
			{"rotr", rotr}
	};
	while (i < 15)
	{
		if (strcmp(command, opcodes[i].opcode) == 0)
			return (opcodes[i].f);
		i++;
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number,
		command), exit(EXIT_FAILURE);
}
