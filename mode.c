#include "monty.h"

/**
 * push_to_stack - Pushes a new node onto the stack.
 * @stack_head: Pointer to the top of the stack.
 * @new_node: The new node to push onto the stack.
 *
 * Description:
 * This function pushes a new node onto the stack and updates the necessary
 * pointers to maintain the stack structure.
 */
void push_to_stack(stack_t **stack_head, stack_t **new_node)
{
	if (!stack_head)
	{
		(*new_node)->prev = NULL;
		(*new_node)->next = NULL;
		*stack_head = (*new_node);
	}
	else
	{
		(*stack_head)->prev = *new_node;
		(*new_node)->next = *stack_head;
		(*new_node)->prev = NULL;
		*stack_head = *new_node;
	}
}

/**
 * push_to_queue - Pushes a new node onto the queue.
 * @queue_rear: Pointer to the rear of the queue.
 * @new_node: The new node to push onto the queue.
 *
 * Description:
 * This function pushes a new node onto the queue and updates the necessary
 * pointers to maintain the queue structure.
 */
void push_to_queue(stack_t **queue_rear, stack_t **new_node)
{
	stack_t *tmp;

	if (!queue_rear)
	{
		(*new_node)->prev = NULL;
		(*new_node)->next = NULL;
		*queue_rear = (*new_node);
	}
	else
	{
		tmp = *queue_rear;
		while (tmp->next)
			tmp = tmp->next;

		tmp->next = *new_node;
		(*new_node)->next = NULL;
		(*new_node)->prev = tmp;
	}
}
