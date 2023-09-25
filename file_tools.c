#include "monty.h"

/**
 * openFile - opens a file
 * @fileName: the file name path
 * Return: void
 */
void openFile(char *fileName)
{
    FILE *fileDescriptor = fopen(fileName, "r");

    if (fileName == NULL || fileDescriptor == NULL)
        err(2, fileName);

    readFile(fileDescriptor);
    fclose(fileDescriptor);
}

/**
 * readFile - reads a file
 * @fd: pointer to file descriptor
 * Return: void
 */
void readFile(FILE *fd)
{
    int lineNumber, format = 0;
    char *buffer = NULL;
    size_t len = 0;

    for (lineNumber = 1; getline(&buffer, &len, fd) != -1; lineNumber++)
    {
        format = parseLine(buffer, lineNumber, format);
    }
    free(buffer);
}

/**
 * parseLine - Separates each line into tokens to determine
 * which function to call
 * @buffer: line from the file
 * @lineNumber: line number
 * @format: storage format. If 0, nodes will be entered as a stack.
 *          If 1, nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */
int parseLine(char *buffer, int lineNumber, int format)
{
    char *opcode, *value;
    const char *delim = "\n ";

    if (buffer == NULL)
        err(4);

    opcode = strtok(buffer, delim);
    if (opcode == NULL)
        return (format);
    value = strtok(NULL, delim);

    if (strcmp(opcode, "stack") == 0)
        return (0);
    if (strcmp(opcode, "queue") == 0)
        return (1);

    findFunction(opcode, value, lineNumber, format);
    return (format);
}

/**
 * findFunction - find the appropriate function for the opcode
 * @opcode: opcode
 * @value: argument of opcode
 * @format: storage format. If 0, nodes will be entered as a stack.
 *          If 1, nodes will be entered as a queue.
 * @lineNumber: line number
 * Return: void
 */
void findFunction(char *opcode, char *value, int lineNumber, int format)
{
    int functionIndex;
    int functionFound;

	instruction_t funcList[] = {
		{"push", add_to_stack},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", pop_top},
		{"nop", nop},
		{NULL, NULL}
	};


    if (opcode[0] == '#')
        return;

    for (functionFound = 1, functionIndex = 0; funcList[functionIndex].opcode != NULL; functionIndex++)
    {
        if (strcmp(opcode, funcList[functionIndex].opcode) == 0)
        {
            callFunction(funcList[functionIndex].f, opcode, value, lineNumber, format);
            functionFound = 0;
        }
    }
    if (functionFound == 1)
        err(3, lineNumber, opcode);
}

/**
 * callFunction - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @op: string representing the opcode.
 * @val: string representing a numeric value.
 * @lineNumber: line number for the instruction.
 * @format: Format specifier. If 0, nodes will be entered as a stack.
 *          If 1, nodes will be entered as a queue.
 */
void callFunction(what_function func, char *op, char *val, int lineNumber, int format)
{
    stack_t *node;
    int isNegativeValue;
    int characterIndex;

    isNegativeValue = 1;
    if (strcmp(op, "push") == 0)
    {
        if (val != NULL && val[0] == '-')
        {
            val = val + 1;
            isNegativeValue = -1;
        }
        if (val == NULL)
            err(5, lineNumber);
        for (characterIndex = 0; val[characterIndex] != '\0'; characterIndex++)
        {
            if (isdigit(val[characterIndex]) == 0)
                err(5, lineNumber);
        }
        node = createNode(atoi(val) * isNegativeValue);
        if (format == 0)
            func(&node, lineNumber);
        if (format == 1)
            addToQueue(&node, lineNumber);
    }
    else
        func(&head, lineNumber);
}
