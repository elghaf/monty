#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef long long ssize_t;

/**
 * struct stack_s - doubly linked list representation of a stack.
 * @n: integer
 * @prev: points to the previous element of the stack.
 * @next: points to the next element of the stack.
 *
 * Description: doubly linked list node structure.
 */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/**
 * struct bus_s - variables - args, file, line content
 * @arg: value
 * @file: pointer to the Monty file
 * @content: line content
 * @lifo: flag change stack.
 */
typedef struct bus_s
{
    char *arg;
    FILE *file;
    char *content;
    int lifo;
} bus_t;

extern bus_t bus;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function.
 * */
typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


char *clean_line(char *content);
void op_push(stack_t **head, unsigned int number);
void op_pall(stack_t **head, unsigned int number);
void op_pint(stack_t **head, unsigned int number);
void op_pop(stack_t **head, unsigned int counter);
void op_swap(stack_t **head, unsigned int counter);
void op_add(stack_t **head, unsigned int counter);
void op_nop(stack_t **head, unsigned int counter);
void op_sub(stack_t **head, unsigned int counter);
void op_div(stack_t **head, unsigned int counter);
void op_mul(stack_t **head, unsigned int counter);
void op_mod(stack_t **head, unsigned int counter);
void op_pchar(stack_t **head, unsigned int counter);
void op_pstr(stack_t **head, unsigned int counter);
void op_rotl(stack_t **head, unsigned int counter);
void op_rotr(stack_t **head, __attribute__((unused)) unsigned int counter);

void op_queue(stack_t **head, unsigned int counter);
void op_stack(stack_t **head, unsigned int counter);
int instruction(char *content, stack_t **head, unsigned int counter, FILE *file);


#endif
