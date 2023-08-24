#include "monty.h"

/**
 * pall - prints all values of stack from the top
 * @stack: the stack
 * @line_number: line number
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	UNUSED(line_number);
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
