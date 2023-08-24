#include "monty.h"

/**
 * mod - computes the rest of the division of the 2nd  top elem by top one
 * @stack: the stack
 * @line_number: line number
 */

void mod(stack_t **stack, unsigned int line_number)
{
	int m;

	if (((*stack) == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't mod, stack yoo short\n", line_number);
		exit(EXIT_FAILURE);
	}
	/* division by 0 */
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	m = ((*stack)->next->n) % ((*stack)->n);
	pop(stack, line_number);
	(*stack)->n = m;
}
