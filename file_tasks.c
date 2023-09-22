#include "monty.h"

/**
 * op_file - opens the file
 * @file_name: file name of staks
 * Return: 0
 */
void op_file(char *file_name)
{
FILE *fd = fopen(file_name, "r");

    if (file_name == NULL || fd == NULL)
	error(2, file_name);
    fclose(fd);
}

/**
 * read_file - reads a file
 * @rd_file: reader of file to search
 * Return: 0
 */
void rd_file(char *file)
{
int line_number, format = 0;
    char *buffer = NULL;
    size_t len = 0;

    for (line_number = 1; getline(&buffer, &len, fd) != -1; line_number++)
    {
        format = parse_line(buffer, line_number, format);
    }
    free(buffer);
}

/**
* format_line - format the file
* @line: line from the file
* @ln: the line number of of the opcode.
* Return: 0
*/
int format_line(char *line, int line_number, int format)
{
int i;
    int flag;

    instruction_t func_list[] = {
        {"push", add_to_stack},
        {"pall", print_stack},
        // ... more entries
        {NULL, NULL}
    };

    if (opcode[0] == '#')
        return;

    for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
    {
        if (strcmp(opcode, func_list[i].opcode) == 0)
        {
            call_fun(func_list[i].f, opcode, value, ln, format);
            flag = 0;
        }
    }
    if (flag == 1)
        error(3, ln, opcode);
}

/**
 * fd_func - find the appropriate function for the opcode
 * @opcode: opcode
 * @value: argument of opcode
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * @ln: line number
 * if 1 nodes will be entered as a queue.
 * Return: 0
 */
void fd_func(char *)
{
if (file_name == NULL || fd == NULL)
{
perror("Error opening file");
return;
}
double min_value = -1.0, value;
int first_value = 1;
while (fscanf(fd, "%lf", &value) != EOF)
{
if (first_value || value < min_value)
{
min_value = value;
first_value = 0;
}
}
if (first_value)
{
printf("No values found in the file.\n");
}
else
{
printf("Minimum value in %s: %lf\n", file_name, min_value);
return;
}

