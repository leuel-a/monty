#include "monty.h"

/**
 * read_file - this function will read a file
 * @stack
 */
void read_file(FILE *fp)
{
	size_t n = 0;
	unsigned int line_number;

	line_number = 1;
	while (getline(&buff, &n, fp) != -1)
	{
		get_instruction(line_number);
		line_number++;
	}
}

void  get_instruction(unsigned int line_number)
{
	instruction_t instruction[] = {
		{"pall", pall},
		{"push", push}
	};
	char *opcode;
	int i, size;

	size = sizeof(instruction) / sizeof(instruction[0]);
	opcode = strtok(buff, " \t\n");

	if (opcode == NULL)
		return;

	for (i = 0; i < size; i++)
	{
		if (strcmp(opcode, instruction[i].opcode) == 0)
		{
			instruction[i].f(&stack, line_number);
			return;
		}
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
