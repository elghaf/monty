#ifndef MONTY_H
#define MONTY_H

#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define STACK 0
#define QUEUE 1


extern int dtada;

extern char *line;
extern char **data;

/**
 * struct stack_s - doubly linked list representation of a stack.
 * @n: integer
 * @prev: points to the previous element of the stack.
 * @next: points to the next element of the stack.
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

/**
 * struct bus_s - variables -args, file, line content
 * @arg: value of arg.
 * @file: pointer to monty file.
 * @content: line content.
 * @lifi: flag change stack queue.
 * Description: carries values through the program
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  bus_t;
extern bus_t bus;


extern instruction_t instruction_code[];

void free_distant(stack_t *head);
void mod(stack_t **stack, unsigned int lines);
void push(stack_t **stacks, unsigned int numbers);
void pall(stack_t **stacks, unsigned int numbers);

void nop(stack_t **stacks, unsigned int numbers);
void pop(stack_t **stacks, unsigned int numbers);

void pint(stack_t **stacks, unsigned int numbers);

void swap(stack_t **stacks, unsigned int numbers);

#endif
