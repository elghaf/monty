#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>

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
	char *buffer;
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

extern FILE *file;
FILE *file;

void (*func_op)(stack_t **, unsigned int count_line);
void opcode_push(stack_t **stack, unsigned int line_number);
void opcode_pall(stack_t **stack, unsigned int line_number);
int _isdigit(char *string);
void opcode_nop(stack_t **stack, unsigned int count_line);
void monty_free(stack_t *stack);
void opcode_pop(stack_t **stack, unsigned int count_line);
int _atoi(char *str, int *num);
void opcode_add(stack_t **stack, unsigned int count_line);
void opcode_pint(stack_t **stack, unsigned int count_line);
void opcode_swap(stack_t **stack, unsigned int count_line);
void (*op(char *f_op, unsigned int i, stack_t **s))(stack_t**, unsigned int);
void opcode_sub(stack_t **stack, unsigned int count_line);
void opcode_div(stack_t **stack, unsigned int count_line);
void opcode_mul(stack_t **stack, unsigned int count_line);
void opcode_mod(stack_t **stack, unsigned int count_line);
void opcode_pstr(stack_t **stack, unsigned int count_line);
void opcode_pchar(stack_t **stack, unsigned int count_line);
void opcode_rotr(stack_t **stack, unsigned int count_line);
void opcode_rotl(stack_t **stack, unsigned int count_line);
#endif /* MONTY_H */
