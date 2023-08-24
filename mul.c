#include "monty.h"

/**
 * mul - multiplies the second top element of the stack with the top onr
 * @stack: the stack
 * @line_number: line number
 */

void mul(stack_t **stack, unsigned int line_number)
{
	int m;

	if (((*stack) == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stdout, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	m = ((*stack)->next->n) * ((*stack)->n);
	pop(stack, line_number);
	(*stack)->n = m;
}
