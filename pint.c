/**
 * pint - Prints a value at the top of the stack, followed by a newline.
 * @stack: Double pointer to the top of the stack.
 * @line: Line number of the current opcode.
 *
 * Return: void
 */
void pint(stack_t **stack, unsigned int line)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
