#include "monty.h"

int dtada = STACK;
char **data = NULL;

/**
 * free_dlistint - Frees a dlistint_t list.
 * @head: Pointer to the head of the list.
 *
 * Description: This function frees the memory allocated for a doubly linked
 * list of integers and sets the head pointer to NULL.
 */
void free_dlistint(stack_t *head)
{
    stack_t *temp;

    while (head)
    {
        temp = head->next;
        free(head);
        head = temp;
    }
}

/**
 * split - Split a string into an array of words.
 * @str: The string to split.
 *
 * Return: A dynamically allocated array of strings containing the words.
 *         The last element of the array is NULL.
 */
char **split(char *str)
{
    char *token = strtok(str, " \t\n\r\f");
    char **array = malloc(sizeof(*array) * 1024);
    size_t i = 0;

    if (!array)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    for (i = 0; token != NULL; i++)
    {
        array[i] = token;
        token = strtok(NULL, " \t\n\r\f");
    }
    array[i] = NULL;
    return (array);
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
            free_dlistint(stack);
            free(line);
            fclose(fp);
            exit(EXIT_FAILURE);
        }
        free(data);
    }
    free_dlistint(stack);
    free(line);
    fclose(fp);
    return (0);
}
