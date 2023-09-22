#include "monty.h"

/**
 * pop_stack - Removes the top element from the stack.
 * @stack_head: Pointer to the head of the stack.
 * @line_number: The line number.
 * Return: No return value.
 */
void pop_stack(stack_t **stack_head, unsigned int line_number)
{
    stack_t *temp_node;

    if (*stack_head == NULL)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        fclose(bus.file); // Assuming bus.file is a global variable
        free(bus.content); // Assuming bus.content is a global variable
        free_stack(*stack_head); // Assuming free_stack is a function to free the stack
        exit(EXIT_FAILURE);
    }

    temp_node = *stack_head;
    *stack_head = temp_node->next;
    free(temp_node);
}

/**
 * do_nothing - Does nothing.
 * @stack_head: Pointer to the head of the stack.
 * @line_number: The line number.
 * Return: No return value.
 */
void do_nothing(stack_t **stack_head, unsigned int line_number)
{
    (void)line_number;
    (void)stack_head;
}

/**
 * print_stack - Prints the stack.
 * @stack_head: Pointer to the head of the stack.
 * @line_number: The line number (not used).
 * Return: No return value.
 */
void print_stack(stack_t **stack_head, unsigned int line_number)
{
    stack_t *temp;
    (void)line_number;

    temp = *stack_head;
    if (temp == NULL)
        return;
    while (temp)
    {
        printf("%d\n", temp->n);
        temp = temp->next;
    }
}

/**
 * push_to_stack - Adds a new node to the stack.
 * @stack_head: Pointer to the head of the stack.
 * @line_number: The line number.
 * Return: No return value.
 */
void push_to_stack(stack_t **stack_head, unsigned int line_number)
{
    int num, i = 0, flag = 0;

    if (bus.arg)
    {
        if (bus.arg[0] == '-')
            i++;
        for (; bus.arg[i] != '\0'; i++)
        {
            if (bus.arg[i] > 57 || bus.arg[i] < 48)
                flag = 1;
        }
        if (flag == 1)
        {
            fprintf(stderr, "L%d: usage: push integer\n", line_number);
            fclose(bus.file); 
            free(bus.content);
            free_stack(*stack_head);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        fclose(bus.file); 
        free(bus.content);
        free_stack(*stack_head);
        exit(EXIT_FAILURE);
    }
    num = atoi(bus.arg);
    if (bus.lifi == 0)
        add_node_to_stack(stack_head, num);
    else
        add_to_queue(stack_head, num);
}
