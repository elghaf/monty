#include "monty.h"
#include <stdio.h>

/**
 * push_node_to_top - Adds a new node to the top of the stack.
 * @stack: Pointer to the address of the top node.
 * @n: Data value.
 * Return: Void.
 */
void push_node_to_top(stack_t **stack, int n)
{
    stack_t *new_node;

    new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    if (*stack)
    {
        new_node->n = n;
        new_node->prev = NULL;
        new_node->next = *stack;
        new_node->next->prev = new_node;
        *stack = new_node;
        return;
    }
    new_node->n = n;
    new_node->prev = NULL;
    new_node->next = NULL;
    *stack = new_node;
}

/**
 * pop_node_from_top - Deletes the node at the top of the stack.
 * @stack: Pointer to the address of the head of the stack.
 * @line_number: Line number.
 * Return: Void.
 */
void pop_node_from_top(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    temp = *stack;

    if (temp)
    {
        *stack = temp->next;
        if (*stack)
            (*stack)->prev = NULL;
        free(temp);
        return;
    }
    fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
    free(temp);
    exit(EXIT_FAILURE);
}

/**
 * print_integer - Prints the value of the topmost stack element.
 * @stack: Pointer to the top node.
 * Return: Void.
 */
void print_integer(stack_t **stack)
{
    if (!*stack) /* Runs if the stack is empty. */
    {
        return;
    }
    fprintf(stdout, "%d\n", (*stack)->n);
}

/**
 * print_stack_values - Prints all the values of the stack.
 * @stack: Pointer to the top node.
 * Return: Void.
 */
void print_stack_values(stack_t **stack)
{
    if (!*stack)
    {
        return;
    }
    while ((*stack)->next)
    {
        fprintf(stdout, "%d\n", (*stack)->n);
        *stack = (*stack)->next;
    }
    fprintf(stdout, "%d\n", (*stack)->n);
}

/**
 * do_nothing - Does literally nothing.
 * @stack: Pointer to the address of the head node pointer of the stack.
 * @line_number: The line number.
 * Return: Nothing.
 */
void do_nothing(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
}
