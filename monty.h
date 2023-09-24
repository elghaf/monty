#ifndef MONTY_H
#define MONTY_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

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
    void (*f)(stack_t **stack, unsigned int new_var);
} instruction_t;

/**
 * struct info_s - variables -args, file, line content
 * @new_arg: value
 * @new_file: pointer to monty file
 * @new_content: line content
 * @new_lifi: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct info_s
{
    char *new_arg;
    FILE *new_file;
    char *new_content;
    int new_lifi;
} info_t;

extern info_t info;
void new_push(stack_t **head, unsigned int new_var);
void new_pall(stack_t **head, unsigned int new_var);

#endif /* MONTY_H */
