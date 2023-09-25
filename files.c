#include "monty.h"

stack_t *stack = NULL;

/**
 * open_and_parse_file - Opens and parses a file
 * @file_path: The path to the file
 * Return: void
 */

void open_and_parse_file(char *file_path)
{
	FILE *file = fopen(file_path, "r");

	if (file_path == NULL || file == NULL)
		err(2, file_path);

	parse_file(file);
	fclose(file);
}

/**
 * parse_file - Reads and parses a file
 * @file: Pointer to the file
 * Return: void
 */

void parse_file(FILE *file)
{
	int line_number, storage_format = 0;
	char *buffer = NULL;
	size_t buffer_len = 0;

	for (line_number = 1; getline(&buffer, &buffer_len, file) != -1; line_number++)
	{
		storage_format = parse_line(buffer, line_number, storage_format);
	}
	free(buffer);
}

/**
 * parse_line - Separates each line into tokens to determine
 * which function to call
 * @line: Line from the file
 * @line_number: Line number
 * @storage_format: Storage format (0 for stack, 1 for queue)
 * Return: Returns 0 if the opcode is stack, 1 if queue
 */

int parse_line(char *line, int line_number, int storage_format)
{
	char *opcode, *value;
	const char *delimiter = "\n ";

	if (line == NULL)
		err(4);

	opcode = strtok(line, delimiter);
	if (opcode == NULL)
		return (storage_format);
	value = strtok(NULL, delimiter);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	find_function(opcode, value, line_number, storage_format);
	return (storage_format);
}

/**
 * find_function - Finds the appropriate function for the opcode
 * @opcode: Opcode
 * @value: Argument of opcode
 * @line_number: Line number
 * @storage_format: Storage format (0 for stack, 1 for queue)
 * Return: void
 */

void find_function(char *opcode, char *value, int line_number, int storage_format)
{
	int i;
	int found = 1;

	instruction_t instruction_list[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"nop", nop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", divide},
		{"mul", multiply},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (i = 0; instruction_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, instruction_list[i].opcode) == 0)
		{
			call_function(instruction_list[i].func, opcode, value, line_number, storage_format);
			found = 0;
		}
	}
	if (found == 1)
		err(3, line_number, opcode);
}

/**
 * call_function - Calls the required function
 * @func: Pointer to the function to be called
 * @opcode: String representing the opcode
 * @value: String representing a numeric value
 * @line_number: Line number for the instruction
 * @storage_format: Storage format (0 for stack, 1 for queue)
 */

void call_function(op_func func, char *opcode, char *value, int line_number, int storage_format)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(opcode, "push") == 0)
	{
		if (value != NULL && value[0] == '-')
		{
			value = value + 1;
			flag = -1;
		}
		if (value == NULL)
			err(5, line_number);
		for (i = 0; value[i] != '\0'; i++)
		{
			if (!isdigit(value[i]))
				err(5, line_number);
		}
		node = create_node(atoi(value) * flag);
		if (storage_format == 0)
			func(&node, line_number);
		if (storage_format == 1)
			add_to_queue(&node, line_number);
	}
	else
		func(&stack, line_number);
}
