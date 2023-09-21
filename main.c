#include "monty.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        return (EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return (EXIT_FAILURE);
    }

    char *line = NULL;
    size_t len = 0;
    unsigned int line_number = 0;
    stack_t *stack = NULL;

    while (getline(&line, &len, file) != -1)
    {
        line_number++;

        // Parse the line and get opcode and argument if any
        char *opcode = strtok(line, " \n\t");
        char *arg = strtok(NULL, " \n\t");

        if (opcode)
        {
            if (strcmp(opcode, "push") == 0)
            {
                if (!arg)
                {
                    fprintf(stderr, "L%d: usage: push integer\n", line_number);
                    free(line);
                    fclose(file);
                    free_stack(&stack);  // Implement a function to free the stack
                    return (EXIT_FAILURE);
                }
                int value = atoi(arg);
                push(&stack, value);
            }
            else if (strcmp(opcode, "pall") == 0)
            {
                pall(&stack, line_number);
            }
            // Add more opcodes as needed
        }
    }

    // Clean up and free resources
    free(line);
    fclose(file);
    free_stack(&stack);  // Implement a function to free the stack
    return (EXIT_SUCCESS);
}
