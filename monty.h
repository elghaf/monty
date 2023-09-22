#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>
extern char **environ;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
	
/* code 1 */
void op_file(char *file_name);
int format_line(char *line, int line_number, int format);
void rd_file(char *file);
void fd_func(char *);

/* code 2 Stacks */
stack_t *create_node(int n);
void free_nodes(void);
void print_stack(stack_t **stack, unsigned int line_number);
void monty_stack(stack_t **stack, unsigned int line_number);
void monty_queue(stack_t **stack, unsigned int line_number);
void monty_fun(op_fun, char *, int, int);
void print_top(stack_t **stack, unsigned int line_number);
void pop_top(stack_t **stack, unsigned int line_number);
void monty_nop(stack_t **stack, unsigned int line_number);
void swap_nodes(stack_t **stack, unsigned int line_number);

/* code 3 */
void add_nod(stack_t **stack, unsigned int line_number);
void sub_nod(stack_t **stack, unsigned int line_number);
void div_nod(stack_t **stack, unsigned int line_number);
void mul_nod(stack_t **stack, unsigned int line_number);
void mod_nod(stack_t **stack, unsigned int line_number);

/* code 4 */
void print_char(stack_t **stack,  unsigned int line_number);
void print_string(stack_t **stack,  unsigned int line_number);
void print_run(stack_t **stack,  unsigned int line_number);

/* code 5 */
void error(int error_code, ...);
void more_error(int error_code, ...);
void str_error(int error_code, ...);
void print_sol(stack_t **stack, unsigned int line_number);

#endif /* _MONTY_H_ */

