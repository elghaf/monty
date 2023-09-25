#include "monty.h"
int n = 0;
stack_t *stack = NULL;
/**
 * execution - Function to execute the commands.
 * @inst_arr : Pointer to array of lines from .m file.
 * @line_number : Number of lines in .m file.
 * Return: Void.
 */
void execution(char **inst_arr, unsigned int line_number)
{
	unsigned int j = 0, i = 1;
	char *cmd[10] = {0}, *args = NULL; /* List of commands*/
	void (*opcode)(stack_t **, unsigned int);

	while (j < line_number)
	{
		i = 1;
		if (strlen(inst_arr[j]) == 1 || check_space(inst_arr[j]) == 1
		|| check_comment(inst_arr[j]) == 1)
			j++;
		else
		{
			inst_arr[j][strlen(inst_arr[j]) - 1] = '\0';
			args = strtok(inst_arr[j], " ");
			cmd[0] = args;
			while (i < 2 && args != NULL)
			{
				args = strtok(NULL, " ");
				cmd[i] = args;
				i++;
			}
			if (strcmp(cmd[0], "push") == 0 &&
			(cmd[1] == NULL || check_int(cmd[1]) == 0))
				fprintf(stderr, "L%u: usage: push integer\n",
				j + 1), exit(EXIT_FAILURE);
			if (strcmp(cmd[0], "push") == 0)
				n = atoi(cmd[1]);
			opcode = gof(cmd[0], j + 1);
			opcode(&stack, j + 1);
			j++;
		}
	}
	free(stack);
}
