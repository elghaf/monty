#include "monty.h"

/**
 * add_stack - Adds the top two elements of the stack.
 * @stk: Double pointer to the beginning of the stack.
 * @line_num: The line number in the Monty bytecode file.
 *
 * Description: This function adds the top two elements of the stack and
 * replaces the second top element with the result.
 */
void add_stack(stack_t **stk, unsigned int line_num)
{
    stack_t *temp;

    if (!*stk || !(*stk)->next)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
        exit(EXIT_FAILURE);
    }
    temp = *stk;

    temp->next->n = temp->next->n + temp->n;
    pop_stack(stk, line_num);
}

/**
 * sub_stack - Subtracts the top element of the stack from the second top element.
 * @stk: Double pointer to the beginning of the stack.
 * @line_num: The line number in the Monty bytecode file.
 *
 * Description: This function subtracts the top element of the stack from
 * the second top element and replaces the second top element with the result.
 */
void sub_stack(stack_t **stk, unsigned int line_num)
{
    stack_t *temp;

    if (!*stk || !(*stk)->next)
    {
        fprintf(stderr, "L%d: can't sub, stack too short\n", line_num);
        exit(EXIT_FAILURE);
    }
    temp = *stk;

    temp->next->n = temp->next->n - temp->n;
    pop_stack(stk, line_num);
}

/**
 * divide_stack - Divides the second top element of the stack by the top element.
 * @stk: Double pointer to the beginning of the stack.
 * @line_num: The line number in the Monty bytecode file.
 *
 * Description: This function divides the second top element of the stack by
 * the top element and replaces the second top element with the result.
 */
void divide_stack(stack_t **stk, unsigned int line_num)
{
    stack_t *temp;

    if (!*stk || !(*stk)->next)
    {
        fprintf(stderr, "L%d: can't div, stack too short\n", line_num);
        exit(EXIT_FAILURE);
    }
    temp = *stk;
    if (temp->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", line_num);
        exit(EXIT_FAILURE);
    }
    temp->next->n = temp->next->n / temp->n;
    pop_stack(stk, line_num);
}

/**
 * mul_stack - Multiplies the second top element of the stack by the top element.
 * @stk: Double pointer to the beginning of the stack.
 * @line_num: The line number in the Monty bytecode file.
 *
 * Description: This function multiplies the second top element of the stack by
 * the top element and replaces the second top element with the result.
 */
void mul_stack(stack_t **stk, unsigned int line_num)
{
    stack_t *temp;

    if (!*stk || !(*stk)->next)
    {
        fprintf(stderr, "L%d: can't mul, stack too short\n", line_num);
        exit(EXIT_FAILURE);
    }
    temp = *stk;

    temp->next->n = temp->next->n * temp->n;
    pop_stack(stk, line_num);
}

/**
 * mod_stack - Computes the remainder of the division of the second top element
 *       of the stack by the top element.
 * @stk: Double pointer to the beginning of the stack.
 * @line_num: The line number in the Monty bytecode file.
 *
 * Description: This function computes the remainder of the division of the
 * second top element of the stack by the top element and replaces the second
 * top element with the result.
 */
void mod_stack(stack_t **stk, unsigned int line_num)
{
    stack_t *temp;

    if (!*stk || !(*stk)->next)
    {
        fprintf(stderr, "L%d: can't mod, stack too short\n", line_num);
        exit(EXIT_FAILURE);
    }
    temp = *stk;
    if (temp->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", line_num);
        exit(EXIT_FAILURE);
    }
    temp->next->n = temp->next->n % temp->n;
    pop_stack(stk, line_num);
}
