#include "monty.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

/**
 * main - Entry point of the Monty interpreter.
 * @argc: Argument count.
 * @argv: Array of arguments.
 * Return: Always 0.
 */
char **opcode_tokens = NULL;

int main(int argc, char **argv)
{
    size_t line_number = 1;
    FILE *file_descriptor;
    char *command_buffer = NULL;
    stack_t *stack = NULL;
    size_t buffer_size = 100;
    int i;

    handle_argument_count(argc);
    file_descriptor = fopen(argv[1], "r");
    handle_file_descriptor(file_descriptor, argv[1]);

    command_buffer = malloc(buffer_size);
    if (!command_buffer)
    {
        fprintf(stderr, "malloc failed\n");
        fclose(file_descriptor);
        exit(EXIT_FAILURE);
    }

    while (fgets(command_buffer, buffer_size, file_descriptor))
    {
        opcode_tokens = tokenize_line(command_buffer);
        free(command_buffer);
        execute_opcode(&stack, opcode_tokens, line_number);

        for (i = 0; opcode_tokens[i] != NULL; i++)
            free(opcode_tokens[i]);
        free(opcode_tokens);
        line_number++;
    }

    free(command_buffer);
    free(opcode_tokens);
    fclose(file_descriptor);
    return (0);
}
