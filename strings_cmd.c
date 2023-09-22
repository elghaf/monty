#include "monty.h"

/**
 * print_char - Prints the Ascii value.
 * @stack: Pointer top node of the stack.
 * @line_number: the line number of of the opcode.
 */
void print_char(stack_t **stack, unsigned int line_number);
{
if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
string_err(12, line_number);
int a = (*stack)->n;
int b = (*stack)->next->n;
int sum = a + b;
pop(stack);
pop(stack);
// Push the sum onto the stack
push(stack, sum);
}

/**
 * print_string - Prints a string.
 * @stack: Pointer to node of the stack.
 * @line_num: the line number of of the opcode.
 */
void print_string(stack_t **stack,  unsigned int line_number);
{
if (stack == NULL || *stack == NULL)
string_err(13, ln);
int value = (*stack)->n;
push(stack, value);
}

/**
 * print_run - the first commande of the stack
 * @stack: Pointer to node of the stack.
 * @line_number: The line number of of the opcode.
 */
void print_run(stack_t **stack,  unsigned int line_number);
{
if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
return;
stack_t *tmp = *stack;
while (tmp->next != NULL)
tmp = tmp->next;
tmp->next = *stack;
(*stack)->prev = tmp;
*stack = (*stack)->next;
(*stack)->prev->next = NULL;
(*stack)->prev = NULL;
}

