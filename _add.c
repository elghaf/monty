#include "monty.h"

/**
 * add_to_stack - Adds a node to the head of the stack
 * @stack: Pointer to the head of the stack
 * @n: New value to be added
 * Return: No return value
 */
void add_to_stack(stack_t **stack, int n)
{
    stack_t *new_node, *temp;

    temp = *stack;
    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        printf("Error\n");
        exit(0);
    }
    if (temp)
        temp->prev = new_node;
    new_node->n = n;
    new_node->next = *stack;
    new_node->prev = NULL;
    *stack = new_node;
}

/**
 * perform_addition - Adds the stack's top two elements.
 * @stack: Pointer to the stack's head
 * @line_number: The line number
 * Return: No return value
 */
void perform_addition(stack_t **stack, unsigned int line_number)
{
    stack_t *current;
    int len = 0, temp;

    current = *stack;
    while (current)
    {
        current = current->next;
        len++;
    }
    if (len < 2)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        fclose(bus.file);
        free(bus.content);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }
    current = *stack;
    temp = current->n + current->next->n;
    current->next->n = temp;
    *stack = current->next;
    free(current);
}

/**
 * perform_multiplication - Multiplies the top two elements of the stack.
 * @stack: Pointer to the stack's head
 * @line_number: The line number
 * Return: No return value
 */
void perform_multiplication(stack_t **stack, unsigned int line_number)
{
    stack_t *current;
    int len = 0, temp;

    current = *stack;
    while (current)
    {
        current = current->next;
        len++;
    }
    if (len < 2)
    {
        fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
        fclose(bus.file);
        free(bus.content);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }
    current = *stack;
    temp = current->next->n * current->n;
    current->next->n = temp;
    *stack = current->next;
    free(current);
}

/**
 * perform_modulo - Computes the remainder of the division of the second
 * top element of the stack by the top element of the stack
 * @stack: Pointer to the stack's head
 * @line_number: The line number
 * Return: No return value
 */
void perform_modulo(stack_t **stack, unsigned int line_number)
{
    stack_t *current;
    int len = 0, temp;

    current = *stack;
    while (current)
    {
        current = current->next;
        len++;
    }
    if (len < 2)
    {
        fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
        fclose(bus.file);
        free(bus.content);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }
    current = *stack;
    if (current->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", line_number);
        fclose(bus.file);
        free(bus.content);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }
    temp = current->next->n % current->n;
    current->next->n = temp;
    *stack = current->next;
    free(current);
}

