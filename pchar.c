#include "monty.h"

/**
 * pchar - prints the char at the top of the slack
 * @stack: the stack
 * @line_number: line number
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	/* if stack is empty: */
	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	/* if value is not in the ascii table */
	if (!isprint((*stack)->n))
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%c\n", (*stack)->n);
}
