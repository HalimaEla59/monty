#include "monty.h"

/**
 * pstr - prints the string starting at the of stack
 * @stack: the stack
 * @line_number: line number
 */

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	UNUSED(line_number);
	while ((temp != NULL) && (temp->n != 0) && (isprint(temp->n)))
	{
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
}
