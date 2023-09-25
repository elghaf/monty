#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

/**
 * struct handle_argument - handle argument of opcode
 *
 * @num: string containg argument
 * @textfile: pointer to the file
 *
 */
typedef struct handle_argument
{
	char *num;
	FILE *textfile;
	char *str;
} handle_t;

extern handle_t arg;
void free_the_stack(stack_t *head);
void Push_To_Stack(stack_t **head, unsigned int n);
void Print_Stack(stack_t **head, unsigned int line_num);
void Top_Of_Stack(stack_t **head, unsigned int line_num);
void pop(stack_t **head, unsigned int line_num);
void swap(stack_t **head, unsigned int line_num);
void add(stack_t **head, unsigned int line_num);
void nop(stack_t **head, unsigned int line_num);
void sub(stack_t **head, unsigned int line_num);
void div_fun(stack_t **head, unsigned int line_num);
void mul_fun(stack_t **head, unsigned int line_num);
void mod_fun(stack_t **head, unsigned int line_num);
void pchar_fun(stack_t **head, unsigned int line_num);
void pstr_fun(stack_t **head, unsigned int line_num);

#endif
