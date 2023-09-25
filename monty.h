#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - Doubly linked list representation of a stack (or queue)
 * @n: Integer value
 * @prev: Points to the previous element of the stack (or queue)
 * @next: Points to the next element of the stack (or queue)
 *
 * Description: Doubly linked list node structure for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - Opcode and its associated function
 * @opcode: The opcode
 * @f: Function to handle the opcode
 *
 * Description: Opcode and its associated function for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *stack;
typedef void (*op_func)(stack_t **, unsigned int);

/* File operations */
void open_and_parse_file(char *file_path);
int parse_line(char *line, int line_number, int storage_format);
void parse_file(FILE *file);
int count_chars(FILE *file);
void find_function(char *opcode, char *value, int line_number, int storage_format);

/* Stack operations */
stack_t *create_node(int value);
void free_stack(void);
void print_stack(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void enqueue(stack_t **stack, unsigned int line_number);

void call_function(op_func func, char *opcode, char *value, int line_number, int storage_format);

void print_top(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);

/* Mathematical operations with nodes */
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void divide(stack_t **stack, unsigned int line_number);
void multiply(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);

/* String operations */
void print_char(stack_t **stack, unsigned int line_number);
void print_str(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);

/* Error handling */
void handle_error(int error_code, ...);

#endif
