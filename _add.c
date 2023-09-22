#include "monty.h"

/**
 * add_elements_to_stack - Adds two elements from the stack.
 * @stack_head: Pointer to the head of our stack.
 * @line_number: The line number.
 * Return: No return value.
 */
void add_elements_to_stack(stack_t **stack_head, unsigned int line_number)
{
    stack_t *current_node;
    int stack_length = 0, sum;

    current_node = *stack_head;
    while (current_node)
    {
        current_node = current_node->next;
        stack_length++;
    }
    
    if (stack_length < 2)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        fclose(bus.file);
        free(bus.content);
        free_stack(*stack_head);
        exit(EXIT_FAILURE);
    }

    current_node = *stack_head;
    sum = current_node->n + current_node->next->n;
    current_node->next->n = sum;
    *stack_head = current_node->next;
    free(current_node);
}


/**
 * add_node_to_stack - Adds a new node to the head of the stack.
 * @stack_head: Pointer to the head of the stack.
 * @new_value: The value for the new node.
 * Return: No return value.
 */
void add_node_to_stack(stack_t **stack_head, int new_value)
{
    stack_t *new_node, *temp_node;

    temp_node = *stack_head;
    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        printf("Error\n");
        exit(0);
    }
    if (temp_node)
        temp_node->prev = new_node;

    new_node->n = new_value;
    new_node->next = *stack_head;
    new_node->prev = NULL;
    *stack_head = new_node;
}


/**
 * multiply_top_two_elements - Multiplies the top two elements of the stack.
 * @stack_head: Pointer to the head of the stack.
 * @line_number: The line number.
 * Return: No return value.
 */
void multiply_top_two_elements(stack_t **stack_head, unsigned int line_number)
{
    stack_t *current_node;
    int stack_length = 0, product;

    current_node = *stack_head;
    while (current_node)
    {
        current_node = current_node->next;
        stack_length++;
    }
    
    if (stack_length < 2)
    {
        fprintf(stderr, "L%d: can't multiply, stack too short\n", line_number);
        fclose(bus.file); 
        free(bus.content);
        free_stack(*stack_head);
        exit(EXIT_FAILURE);
    }

    current_node = *stack_head;
    product = current_node->next->n * current_node->n;
    current_node->next->n = product;
    *stack_head = current_node->next;
    free(current_node);
}

/**
 * compute_modulo - Computes the remainder of the division of the second
 * top element of the stack by the top element of the stack.
 * @stack_head: Pointer to the head of the stack.
 * @line_number: The line number.
 * Return: No return value.
 */
void compute_modulo(stack_t **stack_head, unsigned int line_number)
{
    stack_t *current_node;
    int stack_length = 0, remainder;

    current_node = *stack_head;
    while (current_node)
    {
        current_node = current_node->next;
        stack_length++;
    }
    
    if (stack_length < 2)
    {
        fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
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

    remainder = current_node->next->n % current_node->n;
    current_node->next->n = remainder;
    *stack_head = current_node->next;
    free(current_node);
}
