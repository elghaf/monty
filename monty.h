#ifndef MONTY_H_
#define MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

extern int error;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Opcode Functions */
void add_top_two_elements(stack_t **stack_head, unsigned int line_number);
void divide_top_two_elements(stack_t **stack_head, unsigned int line_number);
void free_stack(stack_t **stack_head, FILE *file_ptr, char *line_buffer);
void tokenize_and_process_line(stack_t **stack_head, FILE *file_ptr, char *line_buffer,
                               unsigned int line_number, int *execution_mode);
int check_mode(char *token, int *execution_mode);
void compute_modulus(stack_t **stack_head, unsigned int line_number);
void push_to_stack(stack_t **stack_head, stack_t **new_node);
void push_to_queue(stack_t **queue_rear, stack_t **new_node);
void multiply_top_two_elements(stack_t **stack_head, unsigned int line_number);
void _nop(stack_t **head, unsigned int line_number);
void print_stack(stack_t **stack_head, unsigned int line_number);
void print_top_char(stack_t **stack_head, unsigned int line_number);
void print_top_value(stack_t **stack_head, unsigned int line_number);
void pop_top_element(stack_t **stack_head, unsigned int line_number);
void print_string_from_stack(stack_t **stack_head, unsigned int line_number);
void push_to_stack_or_queue(stack_t **stack_head, unsigned int line_number, char *arg, int mode);
int is_valid_integer(char *str, int *num, unsigned int line_number);
void usage_error(unsigned int line_number);
void rotate_stack_left(stack_t **stack_head, unsigned int line_number);
void rotate_stack_right(stack_t **stack_head, unsigned int line_number);
void opcode_fail(char *token, unsigned int line_number);
void subtract_top_elements(stack_t **head, unsigned int line_number);
void swap_top_two_elements(stack_t **head, unsigned int line_number);
#endif /* MONTY_H_ */
