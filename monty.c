#include "monty.h"
unsigned int global_line_number = 0;

/**
 * main - The entry point for the interpreter.
 * @argc : Number of arguments.
 * @argv : Pointer to array of args (char *).
 * Return: 0 Success, 1 else.
 */
int main(int argc, char **argv)
{
	unsigned int i, j;
	FILE *file;
	char **instruction_array;

	if (argc == 1 || argc > 2)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	file = fopen(argv[1], "r");
	if (file == NULL)
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]),
			exit(EXIT_FAILURE);
	instruction_array = malloc(sizeof(char *) * 5000);
	if (instruction_array == NULL)
		fprintf(stderr, "Error: malloc failed\n"),
			exit(EXIT_FAILURE);
	while (!feof(file) && !ferror(file))
	{
		instruction_array[global_line_number] = malloc(sizeof(char) * 200);
		if (instruction_array[global_line_number] == NULL)
		{
			for (j = 0; j < global_line_number; j++)
				free(instruction_array[j]);
			fprintf(stderr, "Error: malloc failed\n"),
				exit(EXIT_FAILURE);
		}
		if (fgets(instruction_array[global_line_number], 200, file) != NULL)
			global_line_number++;
	}
	execute_instructions(instruction_array, global_line_number);
	fclose(file);
	for (i = 0; i < global_line_number; i++)
		free(instruction_array[i]);
	free(instruction_array);
	return (0);
}
