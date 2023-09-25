#include "monty.h"

handle_t handle = {NULL, NULL, NULL};

/**
 * camelCaseFunction - function that chooses the opcode
 *
 * @line: string containing the line
 * @head: head of the stack
 * @line_num: line number
 * Return: 0 or 1
 */
int camelCaseFunction(char *line, stack_t **head, unsigned int line_num)
{
    unsigned int i = 0;
    char *delimiter = " \t\n\r", *tok;
    instruction_t arr[] = {
        {"push", push}, {"pint", pint},
        {"pall", pall}, {"pop", pop},
        {"swap", swap}, {"add", add}, {"nop", nop},
        {"sub", sub},{NULL, NULL}
    };
    tok = strtok(line, delimiter);
    if (tok && tok[0] == '#')
        return (0);
    handle.num = strtok(NULL, delimiter);
    while (arr[i].opcode && tok)
    {
        if (strcmp(arr[i].opcode, tok) == 0)
        {
            arr[i].f(head, line_num);
            return (0);
        }
        i++;
    }
    if (tok && arr[i].opcode == NULL)
    {
        fprintf(stderr, "L%d: unknown instruction %s\n", line_num, tok);
        fclose(handle.textfile);
        free(line);
        freeTheStack(*head);
        exit(EXIT_FAILURE);
    }
    return (1);
}

/**
 * freeTheStack - function that frees the stack
 * @head: head of the stack
 */
void freeTheStack(stack_t *head)
{
    stack_t *ptr;
    ptr = head;
    while (head)
    {
        ptr = head->next;
        free(head);
        head = ptr;
    }
}

/**
 * main - main function
 *
 * @argc: number of arguments to function main
 * @argv: array of pointers to char
 * Return: int
 */
int main(int argc, char **argv)
{
    char *line;
    stack_t *head = NULL;
    size_t n = 0;
    int i = 1;
    unsigned int line_num = 0;
    FILE *textfile;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    textfile = fopen(argv[1], "r");
    if (textfile == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    while (i > 0)
    {
        line = NULL;
        line_num++;
        handle.textfile = textfile;
        i = getline(&line, &n, textfile);
        handle.str = line;
        if (i > 0)
        {
            camelCaseFunction(line, &head, line_num);
        }
        i++;
        free(line);
    }
    fclose(textfile);
    freeTheStack(head);
    return (0);
}
