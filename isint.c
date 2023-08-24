#include "monty.h"

/**
 * is_int - checks if string can be used with atoi
 * @s: string
 * Return: 1 or 0
 */

int is_int(char *s)
{
	int i = 0;

	if (s == NULL)
		return (0);
	if (*s == '-')
		i++;
	for (; s[i]; i++)
	{
		if (!isdigit(s[i]))
			return (0);
	}
	return (1);
}
