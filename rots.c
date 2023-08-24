#include "monty.h"

/**
 * rotl - rotates the stack to the top
 * @stack: the stack
 * @line_number: line number
 */

void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int i;

	UNUSED(line_number);
	if (temp != NULL)
		i = temp->n;
	while (temp != NULL)
	{
		if (temp->next != NULL)
			temp->n = temp->next->n;
		else
			temp->n = i;
		temp = temp->next;
	}
}

/** 
 * rotr - rotates the stack to the bottom
 * @stack: the stack
 * @line_number: line number
 */

void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int j;

	UNUSED(line_number);
	while (temp->next != NULL)
		temp = temp->next;
	j = temp->n;
	while (temp->prev != NULL)
	{
		temp->n = temp->prev->n;
		temp = temp->prev;
	}
	temp->n = j;
}
