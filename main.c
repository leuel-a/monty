#include "monty.h"

global_t gVar;

/**
 * main - Entry point for my program
 * @argc: the number of arguments passed
 * @argv: the argumet vector containing the arguments
 *
 * Return: On success, it returns 0. On error, it returns
 * 1, and errno is set appropriately.
 */
int main(int argc, char **argv)
{
	FILE *fd;
	size_t n = 0;
	unsigned int line_number = 1;

	gVar.buff = NULL;
	gVar.stack = NULL;	
	if (argc != 2)
	{
		fprintf(stdout, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&gVar.buff, &n, fd) != EOF)
	{
		parse_line(line_number);
		line_number++;
	}
	fclose(fd);
	free_stack();
	exit(EXIT_SUCCESS);
}

/**
 * parse_line - this function will parse a string passed to it as a
 * function argument
 * @line_number: the line number of the string to be parsed
 *
 * Return: Nothinh
 */
void parse_line(unsigned int line_number)
{
	char *opcode;
	int check;

	opcode = strtok(gVar.buff, " \n\t");
	if (opcode == NULL)
		return;

	check = get_instruction(opcode, line_number);
	if (check == 1)
	{
		fprintf(stdout, "L%d: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}

/**
 * get_instruction - this function will find the instruction of the associated
 * opcode passed to it as a function argument
 * @opcode: the operation code
 * @line_number: the line number
 *
 * Return: If there is a function associated with the desired opcode, it will
 * return 0. If there is not function associated with the desired opcode, it
 * will return 1.
 */
int get_instruction(char *opcode, unsigned int line_number)
{
	instruction_t instructs[] = {
		{"pall", pall},
		{"push", push},
		{ NULL, NULL}
	};
	int i;

	for (i = 0; instructs[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, instructs[i].opcode) == 0)
		{
			instructs[i].f(&gVar.stack, line_number);
			return (0);
		}
	}

	return (1);
}

/**
 * free_stack - this function will free the stack
 *
 * Return: Nothing
 */
void free_stack(void)
{
	stack_t *temp, *head;

	head = gVar.stack;
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
