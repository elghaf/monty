#include "monty.h"

/**
 * execute - Executes the Monty opcode.
 * @line_content: Line content from the Monty file.
 * @stack: Pointer to the head of the linked list (stack).
 * @counter: Line counter.
 * @file: Pointer to the Monty file.
 * Return: 0 on success, 1 on failure.
 */
int execute(char *line_content, stack_t **stack, unsigned int counter, FILE *file)
{
    instruction_t opcodes[] = {
        {"push", op_push},
        {"pall", op_pall},
        {"pint", op_pint},
        {"pop", op_pop},
        {"mod", op_mod},
        {"pchar", op_pchar},
        {"pstr", op_pstr},
        {"rotl", op_rotl},
        {"rotr", op_rotr},
        {"swap", op_swap},
        {"add", op_add},
        {"nop", op_nop},
        {"sub", op_sub},
        {"div", op_div},
        {"mul", op_mul},
        {"queue", op_queue},
        {"stack", op_stack},
        {NULL, NULL}
    };

    unsigned int i = 0;
    char *opcode;

    opcode = strtok(line_content, " \n\t");
    if (opcode && opcode[0] == '#')
        return (0);

    monty_bus.arg = strtok(NULL, " \n\t");

    while (opcodes[i].opcode && opcode)
    {
        if (strcmp(opcode, opcodes[i].opcode) == 0)
        {
            opcodes[i].f(stack, counter);
            return (EXIT_SUCCESS);
        }
        i++;
    }

    if (opcode && opcodes[i].opcode == NULL)
    {
        fprintf(stderr, "L%d: unknown instruction %s\n", counter, opcode);
        fclose(file);
        free(line_content);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }

    return (EXIT_FAILURE);
}
