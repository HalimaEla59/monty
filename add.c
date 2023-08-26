#include "monty.h"

/**
 * add - adds the top 2 elements of the stack
 * @stack: the stack
 * @line_number: line number
 */

void add(stack_t **stack, unsigned int line_number)
{
	int a;

	/* if stack has less than 2 elements: */
	if (((*stack) == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	/* else: */
	a = ((*stack)->n) + ((*stack)->next->n);
	pop(stack, line_number);
	(*stack)->n = a;
}
