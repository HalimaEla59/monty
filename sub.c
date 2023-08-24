#include "monty.h"

/**
 * sub - subtracts the top elemnt of the stack from its second element
 * @stack: the stack
 * @line_number: line number
 */

void sub(stack_t **stack, unsigned int line_number)
{
	int s;

	/* if stack has less than 2 elements: */
	if (((*stack) == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stdout, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	/* else: */
	s = ((*stack)->next->n) - ((*stack)->n);
	pop(stack, line_number);
	(*stack)->n = s;
}
