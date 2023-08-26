#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: stack or queue
 * @line_number: line number
 */

void push(stack_t **stack, unsigned int line_number)
{
	char *argument;
	int value;
	stack_t *res, *temp;

	argument = strtok(NULL, " ");
	if (!is_int(argument))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	value = atoi(argument);

	res = malloc(sizeof(stack_t));
	if (res == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	res->n = value; /*we put the value in stack res*/
	res->prev = NULL;
	res->next = NULL;
	/* 3 cases: case 1: if stack is empty: */
	if ((*stack) == NULL)
		*stack = res;
	/* case 2: if stack is a stack LIFO */
	else if (fifolifo)
	{
		res->next = *stack;
		*stack = res;
	}
	/* case 3: if stack is a queue FIFO */
	else
	{
		temp = *stack;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = res;
		res->prev = temp;
		*stack = res;
	}
}
