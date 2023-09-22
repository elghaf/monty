#include "monty.h"

/**
 * divide_top_two_elements - Divides the top two elements of the stack.
 * @stack_head: Pointer to the head of the stack.
 * @line_number: The line number.
 * Return: No return value.
 */
void divide_top_two_elements(stack_t **stack_head, unsigned int line_number)
{
    stack_t *current_node;
    int stack_length = 0, quotient;

    current_node = *stack_head;
    while (current_node)
    {
        current_node = current_node->next;
        stack_length++;
    }
    
    if (stack_length < 2)
    {
        fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
        fclose(bus.file); // Assuming bus.file is a global variable
        free(bus.content); // Assuming bus.content is a global variable
        free_stack(*stack_head); // Assuming free_stack is a function to free the stack
        exit(EXIT_FAILURE);
    }

    current_node = *stack_head;
    if (current_node->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", line_number);
        fclose(bus.file); // Assuming bus.file is a global variable
        free(bus.content); // Assuming bus.content is a global variable
        free_stack(*stack_head); // Assuming free_stack is a function to free the stack
        exit(EXIT_FAILURE);
    }

    quotient = current_node->next->n / current_node->n;
    current_node->next->n = quotient;
    *stack_head = current_node->next;
    free(current_node);
}

/**
 * execute_opcode - Executes the opcode.
 * @content: Line content.
 * @stack: Pointer to the head linked list (stack).
 * @line_counter: Line counter.
 * @file: Pointer to the Monty file.
 * Return: No return value.
 */
int execute_opcode(char *content, stack_t **stack, unsigned int line_counter, FILE *file)
{
    instruction_t opcodes[] = {
        {"push", f_push}, {"pall", f_pall}, {"pint", f_pint},
        {"pop", f_pop},
        {"swap", f_swap},
        {"add", add_elements_to_stack},
        {"nop", f_nop},
        {"sub", f_sub},
        {"div", divide_top_two_elements},
        {"mul", multiply_top_two_elements},
        {"mod", compute_modulo},
        {"pchar", f_pchar},
        {"pstr", f_pstr},
        {"rotl", f_rotl},
        {"rotr", f_rotr},
        {"queue", f_queue},
        {"stack", f_stack},
        {NULL, NULL}
    };

    unsigned int i = 0;
    char *opcode;

    opcode = strtok(content, " \n\t");
    if (opcode && opcode[0] == '#')
        return 0;

    bus.arg = strtok(NULL, " \n\t");

    while (opcodes[i].opcode && opcode)
    {
        if (strcmp(opcode, opcodes[i].opcode) == 0)
        {
            opcodes[i].f(stack, line_counter);
            return 0;
        }
        i++;
    }

    if (opcode && opcodes[i].opcode == NULL)
    {
        fprintf(stderr, "L%d: unknown instruction %s\n", line_counter, opcode);
        fclose(file);
        free(content);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }

    return 1;
}
