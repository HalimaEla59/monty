#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 * @stack: the stack
 * @line_number: line number
 */

void pint(stack_t **stack, unsigned int line_number)
{
	/* if the stack is empty: */
	if ((*stack) == NULL)
	{
		fprintf(stdout, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	/* else we print the head */
	printf("%d\n", (*stack)->n);
}
