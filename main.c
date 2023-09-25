#include "monty.h"

MontyBus montyBus = {NULL, NULL, NULL, 0};

/**
 * main - Monty code interpreter
 * @argc: number of arguments
 * @argv: Monty file location
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
    char *lineContent;
    FILE *file;
    size_t bufferSize = 0;
    ssize_t bytesRead = 1;
    MontyStack *stack = NULL;
    unsigned int lineCounter = 0;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    montyBus.file = file;

    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (bytesRead > 0)
    {
        lineContent = NULL;
        bytesRead = getline(&lineContent, &bufferSize, file);
        montyBus.content = lineContent;
        lineCounter++;

        if (bytesRead > 0)
        {
            execute(lineContent, &stack, lineCounter, file);
        }

        free(lineContent);
    }

    freeStack(stack);
    fclose(file);

    return (0);
}
