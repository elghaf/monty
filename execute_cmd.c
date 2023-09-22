#include "monty.h"
/**
* free_stack - frees stack
* @stack: pointer to stack
*/
void free_stack(stack_t **stack)
{
	stack_t *cur = *stack;
	stack_t *temp = NULL;

	while (cur != NULL)
	{
		temp = cur->next;
		free(cur);
		cur = temp;
	}
	*stack = NULL;
}
/**
* free_items - frees line, stack, closes file
* @stack: the address to the stack
* @line: pointer to the line
* @file: file pointer
*/
void free_items(stack_t **stack, char **line, FILE **file)
{
	if (*stack != NULL)
		free_stack(stack);
	if (line != NULL)
		free(line);
	if (*file != NULL)
		fclose(*file);
}
/**
* execute_cmd - takes in the stack and line to perform function
* @stack: pointer to stack memory address
* @line: pointer to the line read using getline
* @file: file pointer
* Return: Success or failure status
*/
int execute_cmd(stack_t **stack, char **line, FILE **file)
{
	int c = 0;
	static unsigned int line_num;
	char *temp_opcode;
	instruction_t instruction[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	line_num++;
	temp_opcode = strtok(*line," \n\t");
	if (temp_opcode == NULL)
		return (EXIT_SUCCESS);
	
	while (instruction[c].opcode)
	{
		if (strcmp(temp_opcode, instruction[c].opcode) == 0)
		{
			instruction[c].f(stack, line_num);
			return (EXIT_SUCCESS);
		}
		c++;
	}
	free_items(stack,line, file);
	fprintf(stderr, "L%u: unknown instruction %s\n", line_num, temp_opcode);
	exit(EXIT_FAILURE);
}
