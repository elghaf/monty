#include "monty.h"

/**
 * executeInstruction - executes the opcode
 * @content: line content
 * @stack: pointer to the stack
 * @counter: line counter
 * @file: pointer to monty file
 * Return: 0 on success, 1 on failure
 */
int executeInstruction(char *content, MontyStack **stack, unsigned int counter, FILE *file)
{
    MontyInstruction instructions[] = {
        {"push", f_push}, {"pall", f_pall}, {"pint", f_pint},
        {"pop", f_pop}, {"swap", f_swap}, {"add", f_add},
        {"nop", f_nop}, {"sub", f_sub}, {"div", f_div},
        {"mul", f_mul}, {"mod", f_mod}, {"pchar", f_pchar},
        {"pstr", f_pstr}, {"rotl", f_rotl}, {"rotr", f_rotr},
        {"queue", f_queue}, {"stack", f_stack},
        {NULL, NULL}
    };

    unsigned int i = 0;
    char *opcode;

    opcode = strtok(content, " \n\t");
    if (opcode && opcode[0] == '#')
        return (0);

    montyBus.arg = strtok(NULL, " \n\t");

    while (instructions[i].opcode && opcode)
    {
        if (strcmp(opcode, instructions[i].opcode) == 0)
        {
            instructions[i].f(stack, counter);
            return (0);
        }
        i++;
    }

    if (opcode && instructions[i].opcode == NULL)
    {
        fprintf(stderr, "L%d: unknown instruction %s\n", counter, opcode);
        fclose(file);
        free(content);
        freeStack(*stack);
        exit(EXIT_FAILURE);
    }

    return (1);
}
