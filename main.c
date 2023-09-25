#include "monty.h"

/**
 * main - The monty program.
 * @argc: a pointer to the number of arguments.
 * @argv: a pointer to an arryay of arguments.
 * Return: 0 (Success), otherwise (failuir).
 */
int main(int argc, const char *argv[])
{
	const char *filo;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	filo = argv[1];
	files_name(filo);

	return (0);
}

