#include "monty.h"

int dtada = STACK;
char **data = NULL;

/**
 * free_distant - Frees a free_distant list.
 * @head: Pointer to the head of the list.
 *
 * Description: This function frees the memory allocated for a doubly linked
 * list of integers and sets the head pointer to NULL.
 */
void free_distant(stack_t *stack_head)
{
    stack_t *free_l;

    while (stack_head)
    {
        free_l = stack_head->next;
        free(stack_head);
        free_l = free_l;
    }
}

/**
 * split - Split a string into an array of words.
 * @str: The string to split.
 *
 * Return: A dynamically allocated array of strings containing the words.
 *         The last element of the array is NULL.
 */
char **split(char *split_string)
{
    char *string_oked = strtok(split_string, " \t\n\r\f");
    char **list_arr = malloc(sizeof(*list_arr) * 1024);
    size_t i = 0;

    if (!list_arr)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    for (i = 0; string_oked != NULL; i++)
    {
        list_arr[i] = string_oked;
        string_oked = strtok(NULL, " \t\n\r\f");
    }
    list_arr[i] = NULL;
    return (list_arr);
}

/**
 * main - Entry point of the program
 * @ac: Number of command-line arguments
 * @av: Array of command-line arguments
 * Return: 0 on success, 1 on error
 */
int main(int ac, char **av)
{
    instruction_t instruction_code[] = {
        {"push", push},
        {"pall", pall},
		{"pint",pint},
		{"pop",pop},
		{"swap",swap},
		{"nop", nop},
        {NULL, NULL}
    };
    char *line = NULL;
    FILE *fp;
    size_t size = 0;
    unsigned int line_number = 0;
    int i;
    stack_t *stack = NULL;

    if (ac != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    fp = fopen(av[1], "r");

    if (fp == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", av[1]);
        exit(EXIT_FAILURE);
    }
    while (getline(&line, &size, fp) != -1)
    {
        line_number++;
        if (line[0] == '#')
            continue;
        data = split(line);
        if (data[0] == NULL)
        {
            free(data);
            continue;
        }
        if (strcmp(data[0], "stack") == 0)
        {
            dtada = STACK;
            continue;
        }
        else if (strcmp(data[0], "queue") == 0)
        {
            dtada = QUEUE;
            continue;
        }
        for (i = 0; instruction_code[i].opcode != NULL; i++)
        {
            if (strcmp(data[0], instruction_code[i].opcode) == 0)
            {
                instruction_code[i].f(&stack, line_number);
                break;
            }
        }

        if (instruction_code[i].opcode == NULL)
        {
            fprintf(stderr, "L%u: unknown instruction %s\n", line_number, data[0]);
            free(data);
            free_distant(stack);
            free(line);
            fclose(fp);
            exit(EXIT_FAILURE);
        }
        free(data);
    }
    free_distant(stack);
    free(line);
    fclose(fp);
    return (0);
}
