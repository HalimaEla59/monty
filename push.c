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

	argument = strtok(NULL, "\n \t");
	if(!is_int(argument))
	{
		fprintf(stdout, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	value = atoi(argument);

	res = malloc(sizeof(stack_t));
	if (res == NULL)
	{
		fprintf(stdout, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	/* we put the value in the stack result res */
	res->n = value;
	res->prev = NULL;
	res->next = NULL;
	/* we have three cases: */
	/* case 1: if stack is empty: */
	if ((*stack) == NULL)
		*stack = res;
	/* case 2: if stack is a stack LIFO */
	else if (idx == 1)
	{
		(*stack)->prev == res;
		res->next = *stack;
		*stack = res;
	}
	/* case 3: if stack is a queue FIFO */
	else if (idx == 0)
	{
		temp = *stack;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = res;
		res->prev = temp;
		*stack = res;
	}
}
