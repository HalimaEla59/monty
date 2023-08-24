#include "monty.h"

/**
 * free_stack - frees a stack
 * @h: head of the stack
 */

void free_stack(stack_t *h)
{
	stack_t *parse;

	if (!h)
		return;
	parse = h;
	while (parse)
	{
		parse = h->next;
		free(h);
		h = parse;
	}
}
