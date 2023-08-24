#include "monty.h"

/**
 * main - main function for monty
 * @argc: argument count
 * @argv: array of argument strings
 *
 * Return: exit code
 */

int main(int argc, char **argv)
{
	FILE *file;
	unsigned int line_number = 0;
	char *L = NULL;
	stack_t *top = NULL;
	instruction_t *instruction = NULL;
	size_t size = 0;

	/* check for number of arguments */
	if (argc != 2)
	{
		fprintf(stdout, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	/* open the file */
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stdout, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	/* parse the file */
	while (getline(&L, &size, file) != -1)
	{
		line_number++;
		instruction = parse_line(L);

		if (!(instruction->opcode) || instruction->opcode[0] == '#')
		{
			free(instruction);
			if (L)
				free(L);
			L = NULL;
			continue;
		}
		if (instruction->f)
			instruction->f(&top, line_number);
		else
		{
			fprintf(stdout, "L%d: unknown instruction %s\n",
				line_number, instruction->opcode);
			if (L)
				free(L);
			if (top)
				free_stack(top);
			free(instruction);
			fclose(file);
			exit(EXIT_FAILURE);
		}
		if (L)
			free(L);
		L = NULL;
		free(instruction);
	}
	if (L)
		free(L);
	free_stack(top);
	fclose(file);
	return (0);
}
