#include "monty.h"

/**
 * print_error - Prints error messages based on the error code.
 * @error_code: The error code that determines the message to be printed.
 * @line_num: The line number where the error occurred.
 * @instruction: The instruction associated with the error (if applicable).
 */
static void print_error(int error_code, int line_num, const char *instruction) {
    switch (error_code) {
        case 1:
            fprintf(stderr, "ERROR: Usage: monty file\n");
            break;
        case 2:
            fprintf(stderr, "ERROR: Couldn't open file: %s\n", instruction);
            break;
        case 3:
            fprintf(stderr, "ERROR: L%d: Unknown instruction: %s\n", line_num, instruction);
            break;
        case 4:
            fprintf(stderr, "ERROR: Memory allocation failed\n");
            break;
        case 5:
            fprintf(stderr, "ERROR: L%d: Usage: push integer\n", line_num);
            break;
        case 6:
            fprintf(stderr, "ERROR: L%d: Can't pint, stack is empty\n", line_num);
            break;
        case 7:
            fprintf(stderr, "ERROR: L%d: Can't pop, stack is empty\n", line_num);
            break;
        case 8:
            fprintf(stderr, "ERROR: L%d: Can't perform %s, stack is too short\n", line_num, instruction);
            break;
        case 9:
            fprintf(stderr, "ERROR: L%d: Division by zero\n", line_num);
            break;
        case 10:
            fprintf(stderr, "ERROR: L%d: Can't pchar, value is out of range\n", line_num);
            break;
        case 11:
            fprintf(stderr, "ERROR: L%d: Can't pchar, stack is empty\n", line_num);
            break;
        default:
            break;
    }
}

/**
 * err - Handles general errors and exits the program.
 * @error_code: The error code that determines the message to be printed.
 * @line_num: The line number where the error occurred.
 * @instruction: The instruction associated with the error (if applicable).
 */
void err(int error_code, int line_num, const char *instruction) {
    print_error(error_code, line_num, instruction);
    free_nodes();
    exit(EXIT_FAILURE);
}

/**
 * more_err - Handles errors related to stack operations and exits the program.
 * @error_code: The error code that determines the message to be printed.
 * @line_num: The line number where the error occurred.
 * @instruction: The instruction associated with the error (if applicable).
 */
void more_err(int error_code, int line_num, const char *instruction) {
    print_error(error_code, line_num, instruction);
    free_nodes();
    exit(EXIT_FAILURE);
}

/**
 * string_err - Handles errors related to string operations and exits the program.
 * @error_code: The error code that determines the message to be printed.
 * @line_num: The line number where the error occurred.
 */
void string_err(int error_code, int line_num) {
    print_error(error_code, line_num, NULL);
    free_nodes();
    exit(EXIT_FAILURE);
}
