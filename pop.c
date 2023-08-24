#include "monty.h"

/**
 * pop - removes the top element of the stack
 * @stack: the stack
 * @line_number: line number
 */

void pop(stack_t **stack, unsigned int line_number)
{
	/* if the satck is empty: */
	if ((*stack) == NULL)
	{
		fprintf(stdout, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	/* else: */
	*stack = (*stack)->next;
}
