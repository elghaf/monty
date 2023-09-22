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
 * f_mul - multiplies the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void f_mul(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, temp;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	temp = h->next->n * h->n;
	h->next->n = temp;
	*head = h->next;
	free(h);
}


/**
 * f_mod - computes the rest of the division of the second
 * top element of the stack by the top element of the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void f_mod(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, temp;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = h->next->n % h->n;
	h->next->n = temp;
	*head = h->next;
	free(h);
}
