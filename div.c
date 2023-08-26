#include "monty.h"

/**
 * divv - divides the second top element of stack by the top one
 * @stack: the stack
 * @line_number: line number
 */

void divv(stack_t **stack, unsigned int line_number)
{
	int d;

	if (((*stack) == NULL) || ((*stack)->next ==NULL))
	{
		fprintf(stderr,"L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	/* div by zero: */
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	d = ((*stack)->next->n) / ((*stack)->n);
	pop(stack, line_number);
	(*stack)->n = d;
}
